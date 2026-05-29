#ifndef EXPLICIT_H
#define EXPLICIT_H

#include "constants.h"  

///Explicit header file containing the implicit solver 
///
///Explicit header file containing:
///\n-Explicit solver for the heat equation
///\n-Choice of two methods - The DuFort-Frankel and Richardson Method
///\n-FTCS Step algorithm to compute the first time step of solution as required by the DuFort-Frankel and Richardson Methods

///Function to compute the next step of the solution using FTCS method
///@param v Current step of solution from which the next step of the solution is computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@return vector<double> The computed next step of the solution 
vector<double> FTCS_step(vector<double> v, double r);

///Function to compute the next step of the solution using DuFort-Frankel method
///@param pstep Previous step of solution from which the next step of the solution is computed
///@param cstep Current step of solution from which the next step of the solution is computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@return vector<double> The computed next step of the solution 
vector<double> DFF_step(vector<double> pstep, vector<double> cstep, double r);

///Function to compute the next step of the solution using Richardson method
///@param pstep Previous step of solution from which the next step of the solution is computed
///@param cstep Current step of solution from which the next step of the solution is computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@return vector<double> The computed next step of the solution 
///@warning The Richardson method is unconditionally unstable and will return oscillatory values
vector<double> RCS_step(vector<double> pstep, vector<double> cstep, double r);

///Function to compute the implicit solution of the heat equation calling the DuFort-Frankel and Richardson methods to compute the solution
///@param pstep The initial condition of the equation from which the solution is to be computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@param time Time limit until which the solver is to be run to compute the solution
///@param tstep Time step of the equation used to compute the solution
///@param c Choice corresponding to either DuFort-Frankel or Richardson method
///@return vector<double> The computed solution to the heat equation
vector<double> solve_explicit(vector<double> pstep, double r, double time, double tstep, int c);


#endif
