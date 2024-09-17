#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n){
    for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
    }
    return true;
}

int reverse(int& n){
    int s=0;
    while(n>0){
        int t = n%10;
        s=s*10 + t;
        n/=10;
    }
    return s;
}

int main(){
    int num;
    cout<<"Enter number : ";
    cin>>num;
    if(isprime(num)){
        cout<<num<<" is prime number"<<endl;
    }else{
        cout<<num<<" is not prime number"<<endl;
    }
    int x = reverse(num);
    if(isprime(x)){
        cout<<x<<" is prime number"<<endl;
    }else{
        cout<<x<<" is not prime number"<<endl;
    }
}