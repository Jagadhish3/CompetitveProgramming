#include<iostream>
using namespace std;
int fact(int n){
    int fac = 1;
    for(int i=2;i<=n;i++){
        fac*=i;
    }
    return fac;
}
int main(){
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }
}