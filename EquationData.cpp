#include "EquationData.h"
#include <stdexcept>
#include<iostream>

using namespace std;

//Constructors

///Defualt Constructor
EquationData::EquationData(){
}
///Alternate Constructor - Creates EquationData object using given space step, time step and time values and initialize the solution
EquationData::EquationData(double xspace, double tstep, double time)
{
	if (xspace <= 0) 
		throw out_of_range("space discretisation not possible. Step negative or zero. Enter positive number");
		
	if (tstep <= 0) 
		throw out_of_range("Time marching not possible. Time step negative or zero. Enter positive number.");
		
	dx = xspace;
	dt = tstep;
	time_limit = time;
	initcon();
}

//Accessor Functions

///Accessor function to get the time step value
double EquationData::getDT()
{
	return dt;
}

///Accessor function to get the space discretisation step value
double EquationData::getDX()
{
	return dx;
}


///Accessor function to get the time limit until which the solver is run
double EquationData::getTime()
{
	return time_limit;
}

///Accessor function to get the size of the gridspace on which the solution is computed
int EquationData::getSize()
{
	return (1/dx + 1);
}

///Accessor function to get the solution stored in the object
vector<double> EquationData::getSol()
{
	return T;
}

//Mutator Functions

///Mutator function to update the equation parameters based on user choice
void EquationData::updateParam()
{
	cout<<"\nEnter xspace value\n";
	cin>>dx;
	cout<<"\nEnter timestep value\n";
	cin>>dt;
	if (dx <= 0) 
		throw out_of_range("space discretisation not possible. Step negative or zero. Enter positive number");
		
	if (dt <= 0) 
		throw out_of_range("Time marching not possible. Time step negative or zero. Enter positive number.");
		
	cout<<"\nEnter time limit for solution\n";
	cin>>time_limit;
}

///Mutator function to initialize the solution based on the initial conditions
void EquationData::initcon()
{	
	int s = 1/dx + 1;
	T.push_back(sur_temp);
	for(int i = 1;i<s-1;i++)
		{
			T.push_back(init_temp);
		}
	T.push_back(sur_temp);	
}

///Mutator function to update the solution based on the computation done by the solver
void EquationData::updateSol(vector<double> sol)
{
	T = sol;
}

//Display Functions

///Display function to output the solution to the console
void EquationData::dispSol()
{
	for(int i = 0; i<T.size();i++)
		cout<<T[i]<<endl;
}

///Display function to output the current paramters to the console
void EquationData::dispParam()
{
	cout<<"\nCurrent xspace discretization is: "<<dx<<endl;
	cout<<"\nCurrent time step is: "<<dt<<endl;
	cout<<"\nCurrent time limit is: "<<time_limit<<endl;
}

