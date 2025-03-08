#include<bits/stdc++.h>
using namespace std;

bool isprime(int num){
    if(num<2){
        return false;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int count = 0;
    int num =2 ;
    while(count<n){
        if(isprime(count)){
            count++;
        }
    }

}