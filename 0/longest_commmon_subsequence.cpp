#include<bits/stdc++.h>
using namespace std;


int lcs(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;

            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
    }
int main(){
    string s1,s2;
    cin>>s1>>s2;

    int res=lcs(s1,s2);
    cout<<res;

}

/*
bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j<arr[i-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][target];
    }
*/

/*
bool equalPartition(vector<int>& arr) {
        // code here
        int t=0;
        for(int i:arr){
            t+=i;
        }
        
        if(t%2!=0){
            return false;
        }
        int tar=t/2;
        
        vector<bool> dp(tar+1,true);
        dp[0]=true;
        
        for(int i=0;i<arr.size();i++){
            for(int j=tar;j>=arr[i];j--){
                dp[j]=dp[j]||dp[j-arr[i]];
            }
        }
        return dp[tar];
    }
*/

/*
int nCrHelper(int n, int r, vector<vector<int>>& dp) {
    if (r == 0 || r == n) return 1;  
    if (r > n) return 0;             

     if (dp[n][r] != -1) return dp[n][r];

     dp[n][r] = nCrHelper(n - 1, r - 1, dp) + nCrHelper(n - 1, r, dp);

    return dp[n][r];
}
    int nCr(int n, int r) {
         vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return nCrHelper(n, r, dp);
    }
*/

/*

*/
