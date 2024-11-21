#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int arr[5]={4,3,2,7,9};
    vector<int> vec(arr,arr+5);

    int t=0;

    while(vec.size()>1){
        sort(vec.begin(),vec.end());
        vec[0]=(vec[0]+vec[1]);
        vec.erase(vec.begin()+1);
        t+=vec[0];
    }
    cout<<t;
}