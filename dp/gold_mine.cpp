#include<bits/stdc++.h>
using namespace std;

int gm(int n,int m,vector<vector<int>> v){
   int dp[n][m];

   for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(j==m-1){
                dp[i][j]=v[i][j];
            }else if(i==0 && n==1){
                dp[i][j]=v[i][j+1];
            }else if(i==0 && n>1){
                dp[i][j]=v[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }else if(i==n-1){
                dp[i][j]=v[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }else{
                dp[i][j]=v[i][j]+max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
            }
        }
   }

    int maxi=dp[0][0];
    for(int i=1;i<n;i++){
        if(dp[i][0]>maxi){
            maxi=dp[i][0];
        }
    }
    return maxi;

}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        vector<int> vec;
        for(int j=0;j<m;j++){
            int ele;
            cin>>ele;
           vec.push_back(ele);
            
        }
        v.push_back(vec);
    }

    int res=gm(n,m,v);
    cout<<res;


}