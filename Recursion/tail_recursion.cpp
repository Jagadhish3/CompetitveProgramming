//reccurence relation is at end in case of tail recursion
#include<iostream>
using namespace std;

void print(int n){
    if(n == 0){
        return;
    }

    cout << n <<endl;
    //reccurence relation
    print(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << endl;

    print(n);
}

