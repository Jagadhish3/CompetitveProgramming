#include<iostream>
using namespace std;

int pSmooth_lpf(int num) {
    while (num % 2 == 0) {
        num /= 2;
    }
    int l=2;
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            l=i;
            num /= i;
        }
    }
    if(num>1){
        l=num;
    }
    return l;
}

int pJagged_spf(int num) {
    if (num % 2 == 0) {
        
        return 2;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return i;
        }
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int x,y,z;
        int count = 0;
        cin >> x>>y>>z;
        for (int j = x; j <= y; j++) {
            int a = pSmooth_lpf(j);
            int b = pJagged_spf(j);
            if (a <= z && b <= z) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
