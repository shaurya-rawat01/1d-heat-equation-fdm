#include "explicit.h"

#include<vector>

using namespace std;

///Function to compute the next step of the solution using FTCS method
vector<double> FTCS_step(vector<double> v, double r)
{
	vector<double> T(v.size());
	
	T[0] = sur_temp;  //applying the boundary conditions
				
	for(int i = 1;i<v.size()-1;i++)
	{
		T[i] = (r*(v.at(i+1) + v.at(i-1))) + ((1 - (2*r))*v.at(i));
	}
	
	T.back() = sur_temp; //applying the boundary conditions
	
	return T;
}

///Function to compute the next step of the solution using DuFort-Frankel method
vector<double> DFF_step(vector<double> pstep, vector<double> cstep, double r)
{
	vector<double> T(cstep.size());

		T[0] = sur_temp; //applying the boundary conditions

		for (int i = 1; i < cstep.size() - 1; i++)
		{
			T[i] = (pstep.at(i) + 2*r*(cstep.at(i+1) - pstep.at(i) + cstep.at(i-1)))/(1 + 2 * r);
			
		}

		T.back() = sur_temp;  //applying the boundary conditions
		
		return T;
}

///Function to compute the next step of the solution using Richardson method
vector<double> RCS_step(vector<double> pstep, vector<double> cstep, double r)
{
		vector<double> T(cstep.size());
		
		T[0] = sur_temp;  //applying the boundary conditions

		for (int i = 1; i < cstep.size() - 1; i++)
		{
			T[i] = ((2 * r * (cstep.at(i + 1) - 2 * cstep.at(i) + cstep.at(i - 1))) + pstep.at(i));
		}

		T.back() = sur_temp;  //applying the boundary conditions
		
		return T;

}

///Function to compute the implicit solution of the heat equation calling the DuFort-Frankel and Richardson methods to compute the solution
vector<double> solve_explicit(vector<double> pstep, double r, double time, double tstep, int c)
{
	vector<double> cstep(pstep.size()), nstep(pstep.size());
	cstep = FTCS_step(pstep, r);
	double counter = 0;
	
	switch(c)
	{
		
		case 1:                                      //Case corresponding to DuFort-Frankel Method
			do
			{
				counter += tstep;
				nstep.clear();
				nstep = DFF_step(pstep, cstep, r);
				pstep = cstep;
				cstep = nstep;	
			}while(counter<=time);
		
		case 2:                                      //Case corresponding to Richardson Method
			do
			{
				counter += tstep;
				nstep.clear();
				nstep = RCS_step(pstep, cstep, r);
				pstep = cstep;
				cstep = nstep;	
			}while(counter<=time);
			break;
	}
		
	return cstep;
}

