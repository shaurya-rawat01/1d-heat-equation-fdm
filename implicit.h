#ifndef IMPLICIT_H
#define IMPLICIT_H

///Implicit header file containing the implicit solver 
///
///Implicit header file containing:
///\n-Implicit solver for the heat equation
///\n-Choice of two methods - The Crank-Nicholson and Laasonen Implicit Method
///\n-Thomas Algorithm to solve the implicit matrix

///Function to populate the vector B, where AX = B based on the Crank-Nicholson Method
///@param T Previous solution step based on which vector B will be computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@return vector<double> The populated vector B, where AX=B based on the Crank-Nicholson Method
vector<double> CN_populate(vector<double> T, double r);

///Function to populate the vector B, where AX = B based on the Laasonen Method
///@param T Previous solution step based on which vector B will be computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@return vector<double> The populated vector B, where AX=B based on the Laasonen Method
vector<double> LS_populate(vector<double> T, double r);

///Function to compute vector X, where AX = B using the Thomas tridiagonal algorithm where matrix A is a tridiagonal matrix
///@param ds The side diagonals of the matrix A of the Crank-Nicholson and Laasonen method
///@param dm The main diagonal of the matrix A of the Crank-Nicholson and Laasonen method 
///@return vector<double> The computed X vector where AX = B
vector<double> thomas_transform(double ds, double dm, vector<double> v);


///Function to compute the implicit solution of the heat equation calling the Laasonen and Crank-Nicholson methods and using Thomas Algorithm to compute the solution
///@param sol The initial condition of the equation from which the solution is to be computed
///@param r Constant based on equation parameters where r = diffusivity*dt/(dx*dx)
///@param time Time limit until which the solver is to be run to compute the solution
///@param tstep Time step of the equation used to compute the solution
///@param c Choice corresponding to either Crank-Nicholson or Laasonen method
///@return vector<double> The computed solution to the heat equation
vector<double> solve_implicit(vector<double> sol, double r, double time, double tstep, int c);

#endif
