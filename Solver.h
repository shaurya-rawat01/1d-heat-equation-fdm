#ifndef SOLVER_H
#define SOLVER_H

#include"EquationData.h"
#include "implicit.h"
#include "explicit.h"

///Solver header file containing function to invoke the heat equation solver based on user choice 
///
///Solver header file containing solver function to invoke the heat equation solver based on user choice and output the solution and computation time

///Function to invoke the solver based on EquationData object and mutate it to hold the solved heat equation solution based on the EquationData object parameters
///@param E EquationData object from which parameters are extracted and used to invoke solver based on user choice
void solve(EquationData &E);

#endif
