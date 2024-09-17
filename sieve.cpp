#include<bits/stdc++.h>
using namespace std;
void sieve(int num){
    int p[num] = {0};
    for(int i=2;i<=num;i++){
        for(int j=i*i;j<=num;j+=i){
            if(p[i]==0){
                p[j]=1;
            }
        }
       
    }
     for(int i=2;i<=num;i++){
            if(p[i]==0){
                cout<<i<<" ";
            }
    }
}
int main(){
    int n;
    cin>>n;
    sieve(n);
}