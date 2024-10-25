#include <iostream>
using namespace std;

struct candy {
    int rating;
    int candies;
};

int main() {
    int n;
    cin >> n;

    candy cand[n];
    for (int i = 0; i < n; i++) {
        cin >> cand[i].rating;
        cand[i].candies = 1;  
    }

    for (int i = 0; i < n - 1; i++) {
        if (cand[i + 1].rating > cand[i].rating) {
            cand[i + 1].candies = cand[i].candies + 1;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (cand[i - 1].rating > cand[i].rating && cand[i - 1].candies <= cand[i].candies) {
            cand[i - 1].candies = cand[i].candies + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cand[i].candies;
    }
    cout << sum;

    return 0;
}

