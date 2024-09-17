#include <iostream>
#include <cstdlib>
using namespace std;

int power(int x, unsigned int y, int p) {
    int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        if (y & 1)  // If y is odd, multiply x with result
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p; // Change x to x^2
    }
    return res;
}

bool isPrimeFermat(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Try k times
    while (k > 0) {
        int a = 2 + rand() % (n - 4); // Pick a random number in [2..n-2]
        if (power(a, n - 1, n) != 1)
            return false;
        k--;
    }
    return true;
}

int main() {
    int n = 37;
    int k = 5; // Number of iterations
    isPrimeFermat(n, k) ? cout << "Prime\n" : cout << "Not Prime\n";
    return 0;
}
