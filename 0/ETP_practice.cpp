#include<bits/stdc++.h>
using namespace std;

//Finding prime factors using square root
/*
bool isprime(int num){
    if(num<2){
        return false;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cin>>num;

    for(int i=1;i<=num;i++){
        if(num%i==0 && isprime(i)){
            // while(num%i==0){
                cout<<i<<" ";
                // num/=2;
            // }
        }
    }
    
}
*/

//Fermats method
/*
#include <iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    if(n<2){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}

int main() {
    int n;
    cin>>n;
    if (isPrime(n) || n < 2) {
        cout << "Prime or cannot be factorized" << endl;
        return 0;
    }
    for(int i=sqrt(n);i>=2;i--){
        if(n%i==0){

            if(isPrime(i)){
                if(isPrime(n/i)){
                    cout<<i<<" "<<n/i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
*/

//seive of eratosthenes
/*
int main(){
    int n;
    cin>>n;

    int arr[n] ;
    for(int i=2;i<=n;i++){
        arr[i]=1;
    }

    for(int i=2;i*i<=n;i++){
        if(arr[i]==1){
            for(int j=i*i;j<n;j+=i){
                arr[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(arr[i]==1){
            cout<<i<<" ";
        }
    }


}
*/

//segmented seive
/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform the classic Sieve of Eratosthenes
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to find primes in the range [L, R]
void segmentedSieve(long long L, long long R) {
    // Step 1: Find all primes up to sqrt(R)
    long long limit = sqrt(R);
    vector<int> primes = simpleSieve(limit);

    // Step 2: Create a boolean array for the range [L, R]
    vector<bool> isPrime(R - L + 1, true);

    // Step 3: Mark multiples of each prime in the range [L, R]
    for (int prime : primes) {
        // Find the smallest multiple of prime >= L
        long long start = max(prime * prime, (L + prime - 1) / prime * prime);

        for (long long j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }

    // Step 4: Print the primes in the range
    for (long long i = 0; i <= R - L; ++i) {
        if (isPrime[i] && (i + L > 1)) { // Ignore numbers <= 1
            cout << i + L << " ";
        }
    }
    cout << endl;
}

int main() {
    long long L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;

    segmentedSieve(L, R);

    return 0;
}

*/

//sieve of atkins
/*
#include<iostream>
using namespace std;

void sieveofatkins(int num){
	bool sieve[num+1];
	
	for(int i=0;i<=num;i++){
		sieve[i]=false;
	}

	if(num>2){
		sieve[2]=true;
	}
	if(num>3){
		sieve[3]=true;
	}


	for(int x=1;x*x<=num;x++){
		for(int y=1;y*y<=num;y++){
			int n=(4*x*x)+(y*y);

			if(n<=num && n%12==1||n%12==5){
				sieve[n]=true;
			}

			n=(3*x*x)+(y*y);
			if(n<=num && n%12==7){
				sieve[n]=true;
			}

			n=(3*x*x)-(y*y);
			if(x<y && n<=num && n%12==11){
				sieve[n]=true;
			}
		}
	}

	for(int i=5;i*i<=num;i++){
		if(sieve[i]){
			for(int j=i*i;j<=num;j+=i*i){
				sieve[j]=false;
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(sieve[i]){
			cout<<i<<" ";
		}
	}
}

int main(){
	int n;
	cin>>n;

	sieveofatkins(n);
}
*/

//tiling problem
/*
const int m = 1e9+7;

int count(int num){
    int dp[num+1] = {0};
    if(num==0 || num==1){
        return 1;
    }

    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=num;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[num];
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}
*/

//iterative tiling problem
/*
const int m=1e9 + 7;
int countWays2D(int n) {
    if (n == 0) return 1;  
    if (n == 1) return 1;  

    int prev2 = 1;  
    int prev1 = 1;  
    int current;

    for (int i = 2; i <= n; i++) {
        current = (prev1 + prev2)%m;  
        prev2 = prev1;      
        prev1 = current;
    }
    return current;
}

int main() {
    int n;
    cout << "Enter the width of the 2xN board: ";
    cin >> n;
    cout << "Number of ways to tile the board: " << countWays2D(n) << endl;
    return 0;
}
*/

//Longest incresing subsequence
/*
int lis(vector<int> vec){
    vector<int> dp(vec.size(),1);

    for(int i=1;i<vec.size();i++){
        for(int j=0;j<i;j++){
            if(vec[i]>vec[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    vector<int> vec={2,1,3,5,4};
    cout<<lis(vec);

}

*/

//Longest common subsequence
/*
int lcs(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dp[m+1][n+1] ={};
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         dp[i][j]=0;
    //     }
    // }

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

    cout<<lcs(s1,s2);
}

*/

//binomial coeeficient
/*

const int m=1e9+7;
int ncr(int n,int r){
    vector<vector<int>> dp(n+1,vector<int>(r+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(j==0 || i==j){
                dp[i][j]=1;
            }else{
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%m;
            }
        }
    }
    return dp[n][r];
}

int main(){
    int n,r;
    cin>>n>>r;

    cout<<ncr(n,r);
}
//optimsed
#include <iostream>
#include <vector>
using namespace std;

int ncr(int n, int r) {
    if (r > n) return 0;
    vector<int> dp(r + 1, 0);
    dp[0] = 1; // Base case: C(0, 0) = 1

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[r];
}

int main() {
    int n, r;
    cout << "Enter values for n and r: ";
    cin >> n >> r;

    cout << "nCr(" << n << ", " << r << ") = " << ncr(n, r) << endl;
    return 0;
}

*/

//0/1 knapsack
/*
int knapsac(vector<int> wt,vector<int> val,int w){
    int n=wt.size();

    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j<wt[i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;

    vector<int> wt(n);
    vector<int> val(n);

    for(int i=0;i<n;i++){
        cin>>wt[i] ;
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<knapsac(wt,val,w);

}
*/

//minimum edit distance
/*
int minedit(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
    }
    return dp[m][n];
    }

    int main(){
        string s1,s2;
        cin>>s1>>s2;

        cout<<minedit(s1,s2);
    }

    */
