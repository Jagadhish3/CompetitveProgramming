#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Bag {
    int weight;
    int value;
    double profit;  // Profit ratio (value/weight)
};

bool cmp(Bag a, Bag b) {
    a.profit = (double)a.value / a.weight;
    b.profit = (double)b.value / b.weight;
    return a.profit > b.profit;  // Sort in decreasing order of profit ratio
}

int main() {
    Bag items[3];
    int wt[] = {10, 20, 30};
    int val[] = {50, 70, 90};
    int W = 50;  // Maximum weight capacity of the knapsack
    double profit = 0.0;

    // Initialize items
    for (int i = 0; i < 3; i++) {
        items[i].weight = wt[i];
        items[i].value = val[i];
    }

    // Sort items based on profit ratio
    sort(items, items + 3, cmp);

    // Calculate maximum profit
    for (int i = 0; i < 3; i++) {
        if (items[i].weight <= W) {
            profit += items[i].value;
            W -= items[i].weight;
        } else {
            profit += items[i].value * ((double)W / items[i].weight);
            break;  // Bag is full, stop
        }
    }

    // Output the result
    cout << "Maximum profit: " << profit << endl;

    return 0;
}
