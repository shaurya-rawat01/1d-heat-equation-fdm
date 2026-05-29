#include "Analysis.h"
#include<iostream>

using namespace std;

//Constructors

///Defualt Constructor
Analysis::Analysis(){
}

///Alternate Constructor - Creates Analysis object using given EquationData object and computes the norms
Analysis::Analysis(EquationData E)
{
	this->E = E;	
	compute_analytical();
	error_calc();
	compute_norms();
	dispNorms();
}

//Mutator Methods

///Mutator function to calculate the analytical solution based on parameters provided by the EquationData object;
void Analysis::compute_analytical()
{
	double dx = E.getDX();
	double time = E.getTime();
	
	double x = 0;
	int s = 1/dx + 1;
	
	for(int i = 0; i<s; i++)
	{
		double sum = 0;
		for(double n = 1; n <= 100; n+=1)
		{
			sum += exp(-diffusivity * pow(n * pi / width, 2) * time) * (1 - pow(-1, n)) / (n * pi) * sin(n * pi * x / width);
		}
		
		analytical_sol.push_back(sur_temp + 2*(init_temp - sur_temp)*sum);
		x += dx;	
	}
	
	cout<<"\nFor Analytical Solution:\n";
	write_vector(analytical_sol);
}

///Mutator function to calculate the error vector based on the analytical solution and the computed solution contained in the EquationData object
void Analysis::error_calc()
{
	vector<double> numeric_sol = E.getSol();
	
	for (int i = 0; i < analytical_sol.size(); i++)
		error_vec.push_back(analytical_sol[i] - numeric_sol[i]);
		
	cout<<"\nFor Error Vector:\n";
	write_vector(error_vec);
}

///Mutator function to compute the norms based on the error vector
void Analysis::compute_norms()
{
	one_norm = 0;
	
	for (int i = 0; i < error_vec.size(); i++)
		one_norm += fabs(error_vec[i]);
		
	two_norm = 0;
	
	for (int i = 0; i < error_vec.size(); i++)
		two_norm += fabs(error_vec[i] * error_vec[i]);
		
	two_norm = sqrt(two_norm);
	
	uniform_norm = error_vec[0];
	
	for (int i = 1; i < error_vec.size(); i++)
		if (uniform_norm < fabs(error_vec[i])) 
			uniform_norm = fabs(error_vec[i]);
		
}

//Display Function
		
///Display function to output the computed norms onto the console
void Analysis::dispNorms()
{
	cout<<"The one norm of the error vector is: "<<one_norm<<endl;
	cout<<"The two norm of the error vector is: "<<two_norm<<endl;
	cout<<"The uniform norm of the error vector is: "<<uniform_norm<<endl;	
}
