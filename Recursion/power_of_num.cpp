#include <iostream>
using namespace std;

// Function to calculate (N^R) % 1000000007 using recursion
long long power(int N, int R) {
    // Define the modulus
    long long num = 1000000007; 

    // Base case: any number to the power of 0 is 1
    if (R == 0) {
        return 1;
    }

    // Recursive case: calculate half power
    long long halfPower = power(N, R / 2) % num;

    // If R is even, return halfPower * halfPower
    if (R % 2 == 0) {
        return (halfPower * halfPower) % num;
    } else { // If R is odd, return N * halfPower * halfPower
        return (N * halfPower * halfPower) % num;
    }
}

int main() {
    int N, R;

    // Input: base and exponent
    cout << "Enter base (N): ";
    cin >> N;
    cout << "Enter exponent (R): ";
    cin >> R;

    // Calculate result
    long long result = power(N, R);

    // Output the result
    cout << N << "^" << R << " % 1000000007 = " << result << endl;

    return 0;
}