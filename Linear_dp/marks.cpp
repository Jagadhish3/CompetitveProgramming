#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lt;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        switch (type) {
            case 1: {
                int mark;
                cin >> mark;
                lt.push_back(mark);
                break;
            }
            case 2:
                if (!lt.empty()) {
                    lt.pop_back();
                }
                break;
            case 3:
                if (!lt.empty()) {
                    lt.back() += 5;
                }
                break;
            case 4:
                if (!lt.empty()) {
                    lt.back() -= 5;
                }
                break;
            case 5:
                if (!lt.empty()) {
                    reverse(lt.begin(), lt.end());
                }
                break;
        }
    }

    int res = 0;
    for (int i : lt) {
        res += i;
    }

    cout << res << endl;

    return 0;
}
