#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void prime_factors(int num){
    bool found = false;
    for(int i=2;i<=num;i++){
        if(isprime(i) && num%i==0 && isprime(num/i)){
                cout<<i<<", "<<num/i<<endl;
                found = true;
        }
    }
    if(found==false){
        cout<<"No prime pairs are found";
    }
}

int main(){
    int num;
    cin>>num;
    prime_factors(num);
}
