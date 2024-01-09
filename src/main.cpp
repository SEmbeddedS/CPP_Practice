#include <iostream>
#include <cmath>

using namespace std;

// Function Defination
double func(double x, int a[], int n);                       // Function corresponding to constants entered
double derivative(double x, double h,int a[],int n);         // Derivative of the function
double newtonRaphson(double x, double h, int a[], int n);    // Function to find root using Newton-Raphson method
int menu();                                                  // User Selection menu
void showEquation(int n, int a[]);                           // Show Equation corresponding to Constant Entered 
bool checkForRealRoots(int a[],int n);                       // Function to check that equation have real roots or not

int main() {
    cout << "Welcome to Polynomial Equation Solver\n";
    double initialGuess = 2.0;                               // Initial guess for the root
    double h = 0.0001;                                       // Step size for finite differences
    bool rR = true;                                          // Variable to check for real roots of equation
    int n = menu();                                          // Menu Display and User selection

    int* a = new int[n + 1];                                 // Dynamically allocate memory for an array of size n+1
    for (int i = 0; i <= n; ++i) {
        a[i] = i + 2; 
    }

    char constants[] = {'a','b','c','d'};                    // Constant array and Save user value init
    cout << "Enter equation constant values for selected equation type\n";
    for(int i = 0; i<(n+1); ++i){
        cout << constants[i] << ": ";
        cin >> a[i];
    }

    showEquation(n,a);                                       //Show equation with Constant which entered by user
    //Check for Real roots existance for qaudratic and cubic
    if(n==2||n==3){                                          
    rR = checkForRealRoots(a,n);
    }
    if(rR){
    cout << "Equation have real Roots\n";
    double root = newtonRaphson(initialGuess,h,a,n);         // Call Newton-Rapson function to find root of equation
    cout << "One of the Root is: " << root << endl;
    }
    else{
        cout << "Equation doesn't have real Roots\n";
        cout << "There are complex roots possible\n";
    }
    
    delete[] a;                                             // To free the dynamically allocated memory
    return 0;
}

//Function corresponding to constants entered
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
        //cout << "x: " << x << endl;    //Uncomment to see x Iterative Value
        iterations++;
    }
    cout << "Equation solved in: " << iterations << " Iterations\n";

    return x;
}

//Selection Menu
int menu(){
    float equationType;
    cout << "Select equation type:\n";
    cout << "1. Simple - a*x + b = 0 (e.g., 2x + 3 = 0)\n";
    cout << "2. Quadratic - ax^2 + bx + c = 0 (e.g., 3x^2 + 2x - 81 = 0)\n";
    cout << "3. Cubic - ax^3 + bx^2 + cx + d = 0 (e.g., 5x^3 - 9x^2 + 3x + 1 = 0)\n";
    // Add more equation types here as needed

    cout << "Enter the number corresponding to the equation type: ";
    cin >> equationType;
    //Check if User Enter invalid option number
    if (equationType == 1 || equationType == 2 || equationType == 3){
        return equationType;
    }
    else{
        cout << "Wrong Option Selection! Try Again!\n\n";
        return menu();
    }
}

// Show Equation corresponding to Constant Entered 
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

// Function to check that equation have real roots or not
bool checkForRealRoots(int a[],int n){
    int discriMinant= 0;
    //check (b^2-4ac)>0 for real roots of Quadratic equation
    //Logic Taken from Numerical Analysis of equation book 
    if(n==2){
        discriMinant = (a[1]*a[1])-(4*a[0]*a[2]);               
    }
    //check 18abcd−4(b^3d)+(b^2c^2)−4(ac^3)−27(a^2d^2)>0 for real roots of cubic equation
    //Logic Taken from Numerical Analysis of equation book
    if(n==3){
        discriMinant = (18 * a[0] * a[1] * a[2] * a[3]) -       
                       ( 4 * a[1] * a[1] * a[1] * a[3]) + 
                       ( a[1] * a[1] * a[2] * a[2]    ) - 
                       ( 4 * a[0] * a[2] * a[2] * a[2]) - 
                       (27 * a[0] * a[0] * a[3] * a[3]);

    }
    if(discriMinant>=0){
        return true;
    }
    else{
        return false;
    }
}