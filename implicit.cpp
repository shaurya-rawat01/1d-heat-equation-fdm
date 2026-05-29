#include<vector>
#include "constants.h"

using namespace std;

///Function to populate the vector B, where AX = B based on the Crank-Nicholson Method
vector<double> CN_populate(vector<double> T, double r)
{
	vector<double> v(T.size()-2);
	
	for(int i=0;i<T.size()-2;i++)
	{
		v.at(i) = (2*(1-r)*T.at(i+1)) + (r*T.at(i+2)) + (r*T.at(i));
	}
	
	v.front() += (r*sur_temp); //Applying boundary condition to the vector
	v.back() += (r*sur_temp); //Applying boundary condition to the vector
	
	return v;
}

///Function to populate the vector B, where AX = B based on the Laasonen Method
vector<double> LS_populate(vector<double> T, double r)
{
	vector<double> v(T.size()-2);
	
	for(int i=0;i<T.size()-2;i++)
	{
		v.at(i) = T.at(i+1);
	}
	
	v.front() += (r*sur_temp); //Applying boundary condition to the vector
	v.back() += (r*sur_temp); //Applying boundary condition to the vector
	
	return v;
}

///Function to compute vector X, where AX = B using the Thomas tridiagonal algorithm where matrix A is a tridiagonal matrix
vector<double> thomas_transform(double ds, double dm, vector<double> v)
{
	vector<double> s(v.size()-1), y(v.size()), T(v.size());

	s[0] = ds/dm; //Forward sweep to transform the matrix to upper triangle matrix
	y[0] = v.front()/dm; //Forward sweep to transform the matrix to upper triangle matrix
	
	for(int i=1;i<v.size()-1;i++)
	{   
  		s[i] = ds / (dm - ds * s[i-1]);
  		y[i] = (v[i] - ds * y[i-1]) / (dm - ds * s[i-1]);  		//Forward sweep to transform the matrix to upper triangle matrix
	}
	
	y[v.size()-1] = (v[v.size()-1] - ds * y[v.size()-2]) / (dm - ds * s[v.size()-2]); //Forward sweep to transform the matrix to upper triangle matrix
	
	T[v.size()-1] = y[v.size()-1]; //Reverse sweep to compute the X vector where AX = B
	
	for(int i = v.size()-2;i>=0;i--)
	{
		T[i] = y[i] - s[i] * T[i+1];  //Reverse sweep to compute the X vector where AX = B
	}
	
	return T;
}

///Function to compute the implicit solution of the heat equation calling the Laasonen and Crank-Nicholson methods and using Thomas Algorithm to compute the solution
vector<double> solve_implicit(vector<double> sol, double r, double time, double tstep, int c)
{
	vector<double> mat_c(sol.size()-2); //Vector B where AX=B
	
	double counter = 0;
	
	switch(c)             //Switch statement to select either Crank-Nicholson or Laasonen based on choice passed as argument
	{
		
		case 1:           //Crank-Nicholson case
			do
			{
				counter += tstep;
				mat_c = CN_populate(sol,r);
				sol.clear();
				sol = thomas_transform(-1*r,2+(2*r),mat_c);
				sol.insert(sol.begin(), sur_temp);
				sol.push_back(sur_temp);
			}while(counter<=time);
			break;
			
		case 2:           //Laasonen case
			do
			{
				counter += tstep;
				mat_c = LS_populate(sol,r);
				sol.clear();
				sol = thomas_transform(-1*r,1+(2*r),mat_c);
				sol.insert(sol.begin(), sur_temp);
				sol.push_back(sur_temp);
			}while(counter<=time);
			break;
	}
		
	return sol;
}

