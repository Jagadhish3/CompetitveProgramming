#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int>b){
    return a.second>b.second;
}

int main(){
    vector<int> vec;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);
    }

    unordered_map<int ,int> p;
    for(int i=0;i<n;i++){
        p[vec[i]]++;
    }
    vector<pair<int, int>> sorted_p;

for(auto &s:p){
        sorted_p.push_back(s);
    }
        sort(sorted_p.begin(), sorted_p.end(),cmp);
    // sort(p.begin(),p.end());
    for(auto &s:sorted_p){
        while(s.second--){
            cout<<s.first<<" ";
        }
    }
}