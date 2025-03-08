#include<bits/stdc++.h>
using namespace std;

// int ls(string s1,string s2){
//     int m = s1.length();
//     int n = s2.length();

//     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//     int maxlen = 0;
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=n;j++){
//             if(s1[j-1]==s2[i-1]){
//                 dp[i][j] = 1+dp[i-1][j-1];
//                 maxlen = max(maxlen,dp[i][j]);
//             }else{
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return maxlen;
// }

// int main(){
//     string s1,s2;
//     cin>>s1>>s2;

//     int res = ls(s1,s2);
//     cout<<res;
// }

vector<string> unq(string &s1,string &s2){
    vector<string> v1;
    vector<string> v2;
    // multiset<string> v2;
    string t = "";
    for(char ch:s1){
        if(ch==' '){
            v1.push_back(t);
            t="";
        }else{
            t+=ch;
        }
    }
    v1.push_back(t);
    t = "";
    for(char ch:s2){
        if(ch==' '){
            v2.push_back(t);
            t="";
        }else{
            t+=ch;
        }
    }
    v2.push_back(t);
    vector<string> res;
    // for(int i=0;i<v1.size();i++){
    //     if(v2.find(v1[i])==v2.end()){
    //         res.push_back(v1[i]);
    //     }
    //     v2.erase(v1[i]);

    // }
    unordered_map<string, int> mp;
    // for(int i=0;i<v1.size();i++){
    //     mp[v1[i]]++;
    // }
    for(int i=0;i<v2.size();i++){
        mp[v2[i]]++;
    }
    // vector<string> res;
    for(auto p:v1){
        if(mp[p]>0) {
            mp[p]--;
        }else{
            res.push_back(p);
        }
    } 
    return res;
}

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    vector<string> vec = unq(s1,s2);

    for(auto c:vec){
        cout<<c<<" ";
    }
}