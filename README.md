# 1D Heat Equation FDM Solver

C++ implementation of finite difference methods for the 1D unsteady heat conduction equation, comparing explicit and implicit schemes against an analytical solution.

## Problem

A wall of unit width (1 ft) with uniform initial temperature **T_in = 100°F** subjected to a sudden boundary temperature increase to **T_sur = 300°F** on both surfaces. Thermal diffusivity **D = 0.1 ft²/hr**.

Governing equation (1D unsteady heat conduction):

```
∂T/∂t = D * ∂²T/∂x²
```

Spatial discretization: Δx = 0.05, solved over x ∈ [0, 1].

## Methods Implemented

| Method | Type | Stability |
|---|---|---|
| Crank-Nicholson | Implicit | Unconditionally stable |
| Laasonen Simple Implicit | Implicit | Unconditionally stable |
| DuFort-Frankel | Explicit | Unconditionally stable* |
| Richardson | Explicit | Unconditionally **unstable** |

\* DuFort-Frankel uses FTCS for the first time step, which is conditionally stable.

Implicit schemes are solved using the **Thomas TDMA (Tridiagonal Matrix Algorithm)**.

The analytical solution is computed via Fourier series (10,000 expansion terms) for error benchmarking.

## Error Analysis

Numerical solutions are compared against the analytical solution using three vector norms:

- **L1** — Manhattan norm (sum of absolute errors)
- **L2** — Euclidean norm (root sum of squared errors)  
- **L∞** — Uniform norm (maximum absolute error)

## Code Structure

```
├── main.cpp             # Entry point, parameter setup
├── constants.h/.cpp     # Physical constants, default parameters, file I/O utility
├── EquationData.h/.cpp  # Class encapsulating equation parameters and solution state
├── Solver.h/.cpp        # Solver interface, user scheme selection, timing
├── implicit.h/.cpp      # Crank-Nicholson and Laasonen solvers + Thomas algorithm
├── explicit.h/.cpp      # DuFort-Frankel and Richardson solvers + FTCS bootstrap
├── Analysis.h/.cpp      # Analytical solution, error vector, norm computation
├── Assignement_Group_25.dev     # Dev-C++ project file
└── Makefile.win         # MinGW makefile
```

## Building and Running

**Dev-C++ (Windows):**  
Open the `.dev` project file and hit Build & Run (F11).

**MinGW command line:**
```
mingw32-make -f Makefile.win
```

At runtime, the program prompts for:
1. Whether to customise parameters (Δx, Δt, time limit)
2. Solver type (Implicit / Explicit)
3. Specific scheme within that type

Output includes the numerical solution, analytical solution, error vector, L1/L2/L∞ norms, and computation time in microseconds. Solution vectors are written to `.dat` files for external plotting.

## Default Parameters

| Parameter | Value |
|---|---|
| Δx (space step) | 0.05 |
| Δt (time step) | 0.01 |
| Time limit | 0.5 hr |
| Diffusivity D | 0.1 ft²/hr |
| Initial temperature | 100°F |
| Boundary temperature | 300°F |

## Dependencies

- C++11 standard library only (`<vector>`, `<cmath>`, `<chrono>`, `<fstream>`)
- Compiled and tested with Dev-C++ 5.x / MinGW-w64

## Authors

Christopher Petit · Emmanuel Obi Anyanwu · Shaurya Singh Rawat  
Computational Methods and C++ — Group 25, Cranfield University

---

## Disclaimer

Portions of this README and repository documentation were generated or refined using AI-assisted tools. The underlying implementation, numerical methods, and original project work are my own.

