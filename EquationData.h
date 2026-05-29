#ifndef EQUATIONDATA_H // Guard
#define EQUATIONDATA_H

#include "constants.h" //Useful Constants and vector utility 
#include<vector>
#include<fstream>
#include<string>

using namespace std;

/// EquationData class to store data related to the heat equation
///
///The EquationData class contains:
///\n-Necessary parameters to solve the numerical heat equation
///\n-Constructors to initialize EquationData object with correct paramters
///\n-Accessor functions to retrieve parameters from the object for use in computing
///\n-Mutator functions to update the parameters and solution after solving

class EquationData {
	private: 
		double dx; /// Private double dx. Space discretization step of the Equation.
		double dt;/// Private double dt. Time step of Equation.
		double time_limit;/// Private double time_limit. The maximum time the solver will run until.
		
		vector<double> T;/// Private vector<double> T. Solution vector containing the temperature values.
		
	public:
		
		//Constructors
		
		///Default constructor. Initialize an empty EquationData object.
		///@see EquationData(double xspace, double tstep)
		EquationData();
		
		///Constructor to initialize EquationData object with space and time step values
		///@see EquationData()
		///@param xspace Space discretization step to be assigned
		///@param tstep Time step to be assigned
		EquationData(double xspace, double tstep, double time);
		
		//Accessor Functions
		
		///Accessor function to retrieve the timestep from the object
		///@return double. The timestep of the Equation
		double getDT();
		
		///Accessor function to retrieve the timestep from the object
		///@return double. The space discretization step of the Equation
		double getDX();
		
		///Accessor function to retrieve the timestep from the object
		///@return double. The time limit of the Equation
		double getTime();
		
		///Accessor function to retrieve the timestep from the object
		///@return int. The total size of gridspace
		int getSize();
		
		///Accessor function to retrieve the timestep from the object
		///@return vector<double>. The solution of the equation.
		vector<double> getSol();
		
		///Output Functions
		
		///Output function to display the solution of the equation
		void dispSol();
		
		///Output function to display the parameters of the equation
		void dispParam();
		
		//Mutator Functions
		
		///Mutator function to update the parameters of the equation according to user choice
		void updateParam();
		
		///Mutator function to update the solution based on the output given by the solver function
		///@param sol Solution at a given time provided by the solver
		void updateSol(vector<double> sol);
		
		///Mutator function to set the initial conditions for the equation
		void initcon();
		
};

#endif
