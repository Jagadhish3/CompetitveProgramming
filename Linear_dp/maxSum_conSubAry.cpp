#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[8]={5,3,2,-6,8,12,-2,4};
    int rsum = arr[0];
    int maxi = arr[0];

    for(int i=1;i<8;i++){

       rsum = max(rsum+arr[i],arr[i]);
       maxi = max(rsum,maxi);
        }
       cout<<maxi;
}