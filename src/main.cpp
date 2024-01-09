#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double func(double x, int a[], int n) {
    switch(n)
    {
    case 1:
        return x*a[0]+a[1];
        break;
    case 2:
        return (x * x)*a[0] + x*a[1]+a[2];
        break;
    case 3:
        return (x * x * x)*a[0]+(x * x)*a[1]+x*a[2]+a[3];
        break;
    default:
        return 0;
        break;
    } 
}

// Derivative of the function
double derivative(double x, double h,int a[],int n) {
    return (func(x+h,a,n)-func(x,a,n))/h; 
}

// Function to find root using Newton-Raphson method
double newtonRaphson(double x, double h, int a[], int n) {
    double epsilon = 0.0001; // Desired precision
    int maxIterations = 100; // Maximum number of iterations
    int iterations = 0;

    while (fabs(func(x,a,n)) > epsilon && iterations < maxIterations) {
        x = x - func(x,a,n) / derivative(x,h,a,n);
        cout << "x: " << x << endl;
        iterations++;
    }

    return x;
}

int promt(){
    int equationType;
    std::cout << "Welcome to Polynomial Equation Solver\n";
    std::cout << "Select equation type:\n";
    std::cout << "1. Simple - a*x + b = 0 (e.g., 2x + 3 = 0)\n";
    std::cout << "2. Quadratic - ax^2 + bx + c = 0 (e.g., 3x^2 + 2x + 1 = 0)\n";
    std::cout << "3. Cubic - ax^3 + bx^2 + cx + d = 0 (e.g., 4x^3 + x^2 - 2x + 5 = 0)\n";
    // Add more equation types here as needed

    std::cout << "Enter the number corresponding to the equation type: ";
    std::cin >> equationType;

    return equationType;


}

void showEquation(int n, int a[]){
    cout << "Your equation is: ";
    switch(n)
    {
    case 1:
        cout << a[0] <<"(x)+" << a[1] << " = 0\n";
        break;
    case 2:
        cout << a[0] <<"(x^2)+" << a[1] <<"(x)+" << a[2] << " = 0\n";
        break;
    case 3:
        cout << a[0] <<"(x^3)+" << a[1] <<"(x^2)+" << a[2] <<"(x)+" << a[3]<< " = 0\n";
        break;
    default:
        break;
    }
}

bool checkForRealRoots(int a[]){
    int discriMinant = (a[1]*a[1])-(4*a[0]*a[2]);
    if(discriMinant>0){
        return true;
    }
    else{
        return false;
    }
}


int main() {
    double initialGuess = 1.0; // Initial guess for the root
    double h = 0.0001;
    bool rR = true;
    int n = promt();
    int* a = new int[n + 1]; // Dynamically allocate memory for an array of size n+1

    // Assign values to the array elements
    for (int i = 0; i <= n; ++i) {
        a[i] = i + 2; // Assigning values 2, 3, ..., n+1 to the array
    }
    char constants[] = {'a','b','c','d'}; 
    cout << "Enter equation constant values for selected equation type\n";
    for(int i = 0; i<(n+1); ++i){
        cout << constants[i] << ": ";
        cin >> a[i];
    }
    showEquation(n,a);
    if(n==2){
    rR = checkForRealRoots(a);
    }
    if(rR){
    double root = newtonRaphson(initialGuess,h,a,n);
    cout << "Root is approximately: " << root << endl;
    }
    else{
        cout << "Equation doesn't have real Roots\n";
        cout << "There are two complex roots possible\n";
    }
    
    delete[] a;                                          // To free the dynamically allocated memory
    return 0;
}
