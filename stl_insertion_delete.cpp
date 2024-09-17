#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    
    for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            vec.push_back(ele);
    }
    int val,pos;
    cin>>val>>pos;
    vec.insert(vec.begin()+pos-1,val);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    int del;
    cin>>del;
    vec.erase(vec.begin()+del-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}