#include<iostream>
#include<vector>
using namespace std;


bool luckyhelp(int num,int n){
    if(n>num){
        return true;
    }

    if(num%n==0){
        return false;
    }

    int numm = num - num/n;

    luckyhelp(numm,n+1);
}
bool islucky(int num){
    return luckyhelp(num,2);
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
