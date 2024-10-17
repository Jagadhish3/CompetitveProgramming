#include<iostream>
using namespace std;

int min_edit_dis(const string &str1,const string &str2){
    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){

            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
            }
        }
    }

    return dp[m][n];
}

int main(){
    string s1 = "geek";
    string s2 = "gesrdek";

    cout<<"minimum edit distance is: "<<min_edit_dis(s1,s2);
}