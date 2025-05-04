#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    vector<int> vec;
    float c=0;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);
        sort(vec.begin(),vec.end());

        if(vec.size()%2!=0){
            cout<<fixed<<setprecision(1)<<(float)vec[(vec.size()/2)]<<" ";
        }else{
            cout<<fixed<<setprecision(1)<<(float)(vec[vec.size()/2] + vec[vec.size()/2-1])/2<<" ";
        }
        
    }
}