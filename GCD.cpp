#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    // if(b==0){
    //     return a;
    // }
    // return gcd(b,a%b);

    while(b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int lcm(int a,int b){
    return ((a*b)/gcd(a,b));
}
int main(){
    int a=25;
    int b=45;

    int x=gcd(a,b);
    int y=lcm(a,b);
    cout<<x<<" "<<y;
}