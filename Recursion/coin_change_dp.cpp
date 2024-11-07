#include<iostream>
using namespace std;

int minPartition(int N)
    {
        // code here
        int arr[3] = {2,5,7};
        int dp[4][N+1];
        for(int i=0;i<N+1;i++){
            dp[0][i]=N+1;
        }
        for(int i=0;i<=3;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=3;i++){
            for(int j=1;j<=N;j++){
                if(arr[i-1] > j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
                }
            }
        }
        return dp[3][N];
    }
int main(){
    int x = minPartition(12);
    cout<<x;
}
