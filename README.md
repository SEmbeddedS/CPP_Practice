Polynomial Equation Solver

This program is a polynomial equation solver that utilizes the Newton-Raphson method to find roots for quadratic and cubic equations.
Overview

The program offers functionalities to solve equations of different degrees:

    Simple Linear Equation (ax + b = 0)
    Quadratic Equation (ax^2 + bx + c = 0)
    Cubic Equation (ax^3 + bx^2 + cx + d = 0)

How to Use

Upon running the program, the user is prompted to select an equation type. After choosing the equation type, they input the respective constant values required for that equation.
Menu and Equation Selection

    The menu() function displays available equation types and prompts the user for a selection.
    Based on the selected equation type, the user inputs the constants a, b, c, d as needed.

Newton-Raphson Method

    Root Finding: The core of the solving process is the newtonRaphson() function, employing the Newton-Raphson iterative method to determine the roots of the equation.
    Derivative Calculation: It computes the derivative of the equation using finite differences to approximate the gradient at a given point.

Real Roots Check

    For quadratic and cubic equations (n=2 or n=3), the program verifies the existence of real roots before initiating the root-finding process.
    checkForRealRoots() Function: Utilizes discriminants to ascertain if the equation has real roots.
        Quadratic equation: Checks b^2 - 4ac > 0
        Cubic equation: Applies a complex discriminant equation to determine real roots existence.

Error Handling

    Invalid Selection: The program handles invalid user inputs by prompting for re-selection when an incorrect option is chosen.

Important Notes

    Dynamic Memory Allocation: Utilizes dynamic memory allocation for the array holding equation constants (a[]).
    Precision and Iterations: The solver operates with a specified precision and a maximum number of iterations.

File Structure

    main.cpp: Contains the main logic and function definitions.
    README.md: This file, providing an overview and explanation of the code.