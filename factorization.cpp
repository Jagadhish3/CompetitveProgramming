#include <iostream>
using namespace std;

void primeFactors(int n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // n must be odd at this point. So we can skip one element (i.e., i += 2)
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // This condition is to check if n is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

int main() {
    int n = 315;
    primeFactors(n);
    return 0;
}
/*
#include <iostream>
#include <cmath>
using namespace std;

void primeFactorsSqrt(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
        cout << n << " ";  // Remaining prime number
}

int main() {
    int n = 315;
    primeFactorsSqrt(n);
    return 0;
}
*/