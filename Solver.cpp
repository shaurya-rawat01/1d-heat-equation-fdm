#include "Solver.h"
#include <stdexcept>
#include<iostream>
#include <chrono>

using namespace std;
using std::chrono::steady_clock; //For computing execution time of method
using std::chrono::duration;

///Function to invoke the solver based on EquationData object and mutate it to hold the solved heat equation solution based on the EquationData object parameters
void solve(EquationData &E)
{	
	double r = diffusivity*E.getDT()/(E.getDX()*E.getDX());
	
	cout<<"Would you like to use:\n1.Implicit Scheme\n2.Explicit Scheme\n";
	int c1;
	cin>>c1;
	
	if(c1 > 2 || c1 < 1)
		throw out_of_range(" Invalid choice");
	
	switch(c1)
	{
		case 1:
			{
			cout<<"\nImplicit schemes available:\n1.Crank-Nicholson Method\n2.Laasonen Method(Simple Implicit)\n Select one.\n";
			int c2;
			cin>>c2;
			if(c2 > 2 || c2 < 1)
				throw out_of_range(" Invalid choice");
			auto start = steady_clock::now();
			E.updateSol(solve_implicit(E.getSol(), r, E.getTime(), E.getDT(), c2));
			auto end = steady_clock::now();
			duration<double, std::micro> comp_time = end - start;
			cout<<"\n\nMethod executed in "<<comp_time.count()<<" microseconds\n\n";  //Computation time output in microseconds
			break;
			}
			
		case 2:
			{
			cout<<"\nExplicit schemes available:\n1.DuFort-Frankel Method\n2.Richardson Method(Unstable - Will give invalid solution)\nSelect one.\n";	
			int c3;
			cin>>c3;
			if(c3 > 2 || c3 < 1)
				throw out_of_range(" Invalid choice");
			auto start = steady_clock::now();
			
			E.updateSol(solve_explicit(E.getSol(), r, E.getTime(), E.getDT(), c3));
			auto end = steady_clock::now();
			duration<double, std::micro> comp_time = end - start;
			cout<<"\n\nMethod has executed in "<<comp_time.count()<<" microseconds\n\n"; //Computation time output in microseconds
			break;
			}
	}
	
	cout<<"\nFor the numeric solution:\n";
	write_vector(E.getSol());
	
	E.dispSol();
	
}


