// #include <iostream>
// using namespace std;

// int main() {
//     int n, a = 0, b = 1, c;
//     int steps = 0;

//     cout << "Enter number of terms: ";
//     cin >> n;

//     cout << "Fibonacci Series: ";

//     for (int i = 0; i < n; i++) {
//         cout << a << " ";
//         steps++;

//         c = a + b;
//         steps++;

//         a = b;
//         steps++;

//         b = c;
//         steps++;
//     }

//     cout << "\nStep Count: " << steps << endl;

//     return 0;
// }




#include <iostream>
using namespace std;

int recursiveSteps = 0;
int iterativeSteps = 0;

// Recursive Fibonacci Function
int fibonacciRecursive(int n)
{
    recursiveSteps++;

    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Non-Recursive Fibonacci Function
int fibonacciIterative(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1;

    for (int i = 2; i <= n; i++)
    {
        iterativeSteps++; // Loop iteration
        int temp = a + b;
        iterativeSteps++; // Addition
        a = b;
        iterativeSteps++; // Assignment
        b = temp;
        iterativeSteps++; // Assignment
    }

    return b;
}

// Main Program
int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Enter a non-negative number." << endl;
        return 0;
    }

    // Recursive Method
    int recursiveResult = fibonacciRecursive(n);

    cout << "\nRecursive Method" << endl;
    cout << "Fibonacci(" << n << ") = " << recursiveResult << endl;
    cout << "Step Count = " << recursiveSteps << endl;

    // Iterative Method
    int iterativeResult = fibonacciIterative(n);

    cout << "\nNon-Recursive (Iterative) Method" << endl;
    cout << "Fibonacci(" << n << ") = " << iterativeResult << endl;
    cout << "Step Count = " << iterativeSteps << endl;

    // Complexity Analysis
    cout << "\nTime and Space Complexity:" << endl;

    cout << "\nRecursive Method:" << endl;
    cout << "   Time Complexity  : O(2^n)" << endl;
    cout << "   Space Complexity : O(n)" << endl;

    cout << "\nIterative Method:" << endl;
    cout << "   Time Complexity  : O(n)" << endl;
    cout << "   Space Complexity : O(1)" << endl;

    return 0;
}



// Sample Output
// For input n = 5:
// Enter the value of n: 5

// Recursive Method
// Fibonacci(5) = 5
// Step Count = 15

// Non-Recursive (Iterative) Method
// Fibonacci(5) = 5
// Step Count = 16

// Time and Space Complexity:

// Recursive Method:
//    Time Complexity  : O(2^n)
//    Space Complexity : O(n)

// Iterative Method:
//    Time Complexity  : O(n)
//    Space Complexity : O(1)


// How step count works
// - Recursive: Increments once every time fibonacciRecursive() is called. For n=5, it is called 15 times.
// - Iterative: Counts four operations per loop iteration: loop iteration, addition, and two assignments. For \(n=5\), the loop runs 4 times, giving 4 x 4 = 16 steps.
// Important for your DAA practical: Step count depends on which operations you choose to count. This program counts recursive function calls and selected iterative operations, so the two counts are not a direct, equal-cost comparison of every operation performed.




// Real-life Applications of Fibonacci
// - Recursive Fibonacci: Used in learning recursion, mathematical problem-solving, and algorithms that break problems into smaller subproblems.
// - Iterative Fibonacci: Used to generate Fibonacci sequences efficiently in financial models, nature-pattern simulations, and algorithmic calculations.
// Time and Space Complexity
// Method	Time Complexity	Space Complexity
// Recursive	\(O(2^n)\)	\(O(n)\)
// Iterative	\(O(n)\)	\(O(1)\)

// In short:
// - Recursive: Recalculates values repeatedly, so it becomes slow for large \(n\).
// - Iterative: Calculates each value once, making it faster and more memory-efficient.