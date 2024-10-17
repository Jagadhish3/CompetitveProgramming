#include <iostream>
#include <iomanip> // for setting precision
using namespace std;

// Recursive function to find the amount of water in the (R, C) glass
double findWater(int K, int R, int C) {
    // Base cases
    if (C > R || C < 1) {
        return 0;  // Glass doesn't exist
    }
    if (R == 1 && C == 1) {
        return K;  // Top glass gets all the poured water initially
    }

    // Get water from the two glasses above
    double leftParent = (findWater(K, R - 1, C - 1) - 1) / 2.0;
    double rightParent = (findWater(K, R - 1, C) - 1) / 2.0;

    // If a parent glass has less than 1 unit, it can't overflow
    if (leftParent < 0) leftParent = 0;
    if (rightParent < 0) rightParent = 0;

    // Total water in the current glass
    return leftParent + rightParent;
}

double waterOverflow(int K, int R, int C) {
    // Use recursion to get the water amount in the Cth glass of Rth row
    double water = findWater(K, R, C);

    // Water in each glass is capped at 1 unit
    return min(1.0, water);
}

int main() {
    int K = 8, R = 3, C = 3;
    cout << fixed << setprecision(6) << waterOverflow(K, R, C) << endl;
    return 0;

}