#include<iostream>
using namespace std;

int main(){
    int num = 2;
    
    if(num%2==0){
    while(num%2==0){
        num = num/2;
        }
    }

    for(int i=3;i*i<=num;i+=2){
        if(num%i == 0){
            num/=i;
        }
    }
    int p;
    cin>>p;
    if(num<=p){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

}