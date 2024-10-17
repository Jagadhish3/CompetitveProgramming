#include<iostream>
using namespace std;

int main(){
    int num = 49;
    if(num%2==0){
        // cout<<"2 ";
    
    while(num%2==0){
        // cout<<"2 ";
        num = num/2;
    }
    }

    for(int i=3;i*i<=num;i+=2){

        if(num%i == 0){
            num/=i;
            // cout<<i<<" ";
        }
    }
    if(num>1){
        cout<<num;
    }
}