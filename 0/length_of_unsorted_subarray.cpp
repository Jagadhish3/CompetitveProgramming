#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=12;
    int arr[n]={10,12,20,30,25,31,32,40,33,35,50,60};
    

    int unsorted[n];

    for(int i=0;i<n;i++){
        unsorted[i]=arr[i];
    }

    sort(arr,arr+n);
    int s=0;
    int e=n-1;

    for(int i=0;i<n;i++){
        if(arr[i]!=unsorted[i]){
            s=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=unsorted[i]){
            e=i;
            break;
        }
    }
    if(s==0&&e==n-1){
        cout<<"0";
    }else{
    cout<<s+e+1;
    }
}