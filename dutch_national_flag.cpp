#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int arr[n] = {1,0,2,1,0};

    int l = 0;
    int r = n-1;
    int m = 0;

    while(m<=r){
        if(arr[m]==2){
            swap(arr[r],arr[m]);
            r--;
        }else if(arr[m]==0){
            swap(arr[m],arr[l]);
            l++;
            m++;
        }else{
        m++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}