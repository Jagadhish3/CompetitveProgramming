#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> num){
    int n=num.size();
    vector<int> vec(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[j]<num[i]){
                vec[i]=max(vec[i],vec[j]+1);
            }
        }
    }
    int x=vec[0];
    for(int i=1;i<n;i++){
        if(vec[i]>x){
            x=vec[i];
        }
    }
    return x;
}

int main(){

    string s1;
    cin>>s1;
    string s="";
    vector<int> vec;
    for(char ch:s1){
        if(ch!=','){
            s+=ch;
        }else{
            vec.push_back(stoi(s));
            s="";
        }
    }
    vec.push_back(stoi(s));
    int res=lis(vec);
    cout<<res;


}