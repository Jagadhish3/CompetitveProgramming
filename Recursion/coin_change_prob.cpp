#include<iostream>
using namespace std;


int max_possible_sum_util(int *d,int index,int N){
    if(N==0){
        return 1;
    }
    if(N<0){
        return 0;
    }
    if (N > 0 && index == sizeof(d)) {
        return 0;
    }


    return max_possible_sum_util(d,index,N-d[index])+max_possible_sum_util(d,index+1,N-d[index]);
}
int max_possible_sum(int d[],int N){
    return max_possible_sum_util(d,0,N);
}
int main(){
    int n;
    cout<<"Enter no of denominations: ";
    cin>>n;

    int denom[n];
    cout<<"Enter denominations: ";
    for(int i=0;i<n;i++){
        cin>>denom[i];
    }
    int N;
    cout<<"Enter sum: ";
    cin>>N;

    int res = max_possible_sum(denom,N);
    cout<<res;
}