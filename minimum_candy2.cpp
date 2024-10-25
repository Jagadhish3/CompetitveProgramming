#include<iostream>
using namespace std;

int main(){
    int r[7]={1,2,3,4,5,2,1};
    int c[7];

    for(int i=0;i<7;i++){
        c[i]=1;
    }

    int n=7;

    for(int i=1;i<n;i++){
        if(r[i]>r[i-1]){
            c[i]=c[i-1]+1;
        }
    }
    int t=c[n-1];
    for(int i=n-2;i>=0;i--){
        if(r[i]>r[i+1]){
            c[i]=std::max(c[i],(c[i+1]+1));
        }
        t+=c[i];
    }
    cout<<t;
}