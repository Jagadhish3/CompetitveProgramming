#include<iostream>
#include<vector>
using namespace std;

void remove(vector<int>& V, int step) {
    if (step >= V.size()) {
        return;
    }

    for (int i = step - 1; i < V.size(); i += step) {
        V.erase(V.begin() + i);
        i--;
    }

    remove(V, step + 1);
}

bool islucky(int num) {
    if (num % 2 == 0) {
        return false;
    }

    vector<int> vec;
    for (int i = 1; i <= num; i++) {
        vec.push_back(i);
    }

    remove(vec, 2);

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == num) {
            return true;
        }
    }

    return false;
}

int main() {
    int number;
    cout << "Enter a number to check if it's lucky: ";
    cin >> number;

    if (islucky(number)) {
        cout << number << " is a lucky number!" << endl;
    } else {
        cout << number << " is not a lucky number." << endl;
    }

    return 0;
}
