#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "EquationData.h"

///Analysis class to perform analysis and store information based on the EquationData object containing the solution
///
///Analysis class contains:
///\n-Analysis parameters by which performance of the various methods in the solver can be analysed by
///\n-Constructors to initialize Analysis object with correct data to perform analysis on
///\n-Mutator functions which compute the parameters from the EquationData object to help us in analysis
///\n-Display functions which output the parameters based on which the performance of the method is analysed
///@see EquationData

class Analysis{
	private: 
		double one_norm; //Private double one_norm. Store the Manhattan(Absolute) Norm of the error vector
		double two_norm; //Private double two_norm. Store the Euclidean Norm of the error vector
		double uniform_norm; //Private uniform_norm. Store the Uniform(Max) Norm of the error vector
	
		vector<double> error_vec; //Private vector<double> error_vec. Stores the error vector calculated between the numerical and analytical method
		vector<double> analytical_sol; //Private vector<double> analytical_sol. Stores the analytical solution to the heat equation
		
		EquationData E; // Private EquationData E. Stores the EquationData object containing the computed solution
		
	public:
		
		//Constructors
		
		///Default constructor. Initialize an empty Analysis object.
		///@see Analysis(EquationData E)
		Analysis();
		
		//Constructor to initialize Analysis object with EquationData object containing computed solution
		///@see Analysis()
		///@param E Object containing computed solution to be analysed
		Analysis(EquationData E);
		
		//Display Function
		
		///Display function to output the computed norms onto the console
		void dispNorms();
		
		//Mutator Functions
		
		///Mutator function to calculate the analytical solution based on parameters provided by the EquationData object;
		void compute_analytical();
		
		///Mutator function to calculate the error vector based on the analytical solution and the computed solution contained in the EquationData object
		void error_calc();
		
		///Mutator function to compute the norms based on the error vector
		void compute_norms();
};

#endif
