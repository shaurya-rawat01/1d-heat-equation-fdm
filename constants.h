#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<cmath>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

const double pi = atan(1)*4;  //pi calculation

const double delta_t = 0.01;  //Default time step
const double delta_x = 0.05;  //Default space discretization step

const double diffusivity = 0.1; //Default Diffusivity
const double width = 1.0; //Default width

const double sur_temp = 300.0; //Default Surface Temperature
const double init_temp = 100.0; //Default Initial Temperature

const double max_time = 0.5;  //Default time limit for solver

///Function to write vector into dat file
///@param v The vector to be wriiten into dat file
void write_vector(const vector<double>& v);

#endif

