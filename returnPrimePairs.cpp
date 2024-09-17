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
void sum_of_pairs(int num){
    int max = 0;
    int x=0,y=0;
    int i,j;
    for(i=2;i<=num;i++){
            for(j=2;j<=num;j++){
                if(isprime(i) && isprime(j) &&(i+j)>max && (i+j)<=num){
                    max = (i+j);
                    x=i;
                    y=j;
                }
            }
    }
    cout<<"Max nearest sum is "<<max<<" with "<<x<<", "<<y;
}

int main(){
    int num;
    cin>>num;
    sum_of_pairs(num);
}