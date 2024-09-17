#include<iostream>
using namespace std;

int main(){
    int primes[30];
    for(int i=2;i<=30;i++)
        primes[i]=1;


for(int i=2;i<=30;i++){
    if(primes[i]==1){
        for(int j=i*i;j<=30;j+=i){
            primes[j]=0;
        }
    }
}
int count = 0;
for(int i=2;i<=30;i++){
    cout<<primes[i]<<" ";
    if(primes[i]==1){
        count = count + i;
    }
    
}
cout<<endl;
for(int i=2;i<=30;i++){
    if(primes[i]==1){
        cout<<i<<" ";
    }
    
}
cout<<endl<<count;
}