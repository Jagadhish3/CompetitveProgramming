#include<bits/stdc++.h>
using namespace std;

/*
void insert(int arr[],int& n,int ele,int pos){

    if(pos>n+1 || pos<0){
        return;
    }
    for(int i=n;i>=pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1]=ele;
    n++;
}

void delet(int arr[],int& n,int pos){
    if(pos>n || pos<0){
        return;
    }
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void arrange(int arr[],int n){
    int idx=0;
    int res[n];
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            res[idx++]=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            res[idx++]=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        arr[i]=res[i];
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n=5;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arrange(arr,n);
// delet(arr,n,2);
    // insert(arr,n,21,4);
    display(arr,n);
}

*/
//spiral matrix
/*
int main(){
    int m,n;
    cin>>m>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int idx=0;
    int x=m*n;
    int res[x];
    int top=0;
    int left=0;
    int bottom=m-1;
    int right=n-1;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[idx++]=arr[top][i];
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[idx++]=arr[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                res[idx++]=arr[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res[idx++]=arr[i][left];
            }
            left++;
        }
    }
    for(int i=0;i<x;i++){
        cout<<res[i]<<" ";
    }

}
*/

//diagonal traversal
/*
int main(){
    int m,n;
    cin>>m>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
int dir=0;
int row=0;
int col=0;
int i=0;
int x=m*n;
int res[x];
while(i<x){
    res[i++]=arr[row][col];
    if(dir==0){
        if(col==n-1){
            dir=1;
            row++;
        }else if(row==0){
            dir=1;
            col++;
        }else{
        row--;
        col++;
    }
    }else{
        if(row==m-1){
            dir=0;
            col++;
        }else if(col==0){
            dir=0;
            row++;
        }else{
            row++;
            col--;
        }
    }
}
for(int j=0;j<x;j++){
    cout<<res[j]<<" ";
}

}

*/

//pangram
/*
int main(){
    string s1;
    getline(cin,s1);

    vector<int> vec(26,0);

    for(char ch:s1){
        vec[ch-'a']++;
    }

    for(int i=0;i<26;i++){
        if(vec[i]==0){
            cout<<char(i+'a')<<" ";
        }
    }
}
*/

//anagram
/*
bool isanagram(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    if(m!=n){
        return false;
    }

    int arr[26]={};
    for(char ch:s1){
        ch=tolower(ch);
        arr[ch-'a']++;
    }
    for(char ch:s2){
        ch=tolower(ch);
        arr[ch-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
    
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(isanagram(s1,s2)){
        cout<<"True";
    }else{
        cout<<"False";
    }
}
*/

//common largest prime factor
/*
bool isprime(int num){
    if(num<2){
        return false;
    }

    for(int i=2;i*i<=num;i++){
        if(num%i==2){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mini=arr[0];
    for(int i=1;i<n;i++){
        if(mini>arr[i]){
            mini=arr[i];
        }
    }

    vector<int> vec;
    for(int i=2;i<=mini/2;i++){
        if(isprime(i)&&mini%i==0){
            vec.push_back(i);
        }
    }
    int count;
    int ele=0;
    for(int i=vec.size()-1;i>=0;i--){
        count=0;
        for(int j=0;j<n;j++){
            if(arr[j]%vec[i]==0){
                count++;
            }
        }
        if(count==n){
            if(vec[i]>ele){
                ele=vec[i];
            }
        }
    }
    if(count==n){
        cout<<ele;
    }else{
        cout<<1;
    }

}
*/

//second largest
/*
int gfd(int num){
    while(num>=10){
        num/=10;
    }
    return num;
}
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(gfd(t));
    }
    sort(v.begin(),v.end(),greater<int>());
    
    string largest="";
    string secLargest="";
    for(int i:v){
        largest+=to_string(i);
    }
    
    secLargest=largest;
    for(int i=v.size()-2;i>=0;--i){
        if(v[i]!=v[i+1]){
            swap(secLargest[i],secLargest[i+1]);
            break;
        }
    }
    cout<<secLargest;
    return 0;
}
*/

//first occurence of uppercase letter
/*
int main(){
    string s1;
    cin>>s1;

    char c='\0';

    for(char ch:s1){
        if(ch>='A'&&ch<='Z'){
            c=ch;
            break;
        }
    }
    int count=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]==c){
            count++;
        }
    }
    cout<<count;
}

*/

//peak element
/*
int peekelem(int arr[], int n)
{
    // first or last element is peak element
    if (n == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    // check for every other element
    for (int i = 1; i < n - 1; i++) {

        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int vec=peekelem(arr,n);
    cout<<vec;
}
*/

//minproduct
/*#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minprodut(vector<int> vec) {
    int z = 0;  
    int n = 0;  
    int p = 0;  
    int prod = 1;  
    int mini = INT_MAX;  
    int maxi = INT_MIN;  

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            z++;  
            continue;
        }

        if (vec[i] < 0) {
            n++;  
            maxi = max(maxi, vec[i]);  
        }

        if (vec[i] > 0) {
            p++;  
            mini = min(mini, vec[i]);  
        }

        prod *= vec[i];  
    }

     if (n == vec.size() || (n == 0 && z > 0)) {
        return 0;
    }

     if (p == vec.size()) {
        return mini;
    }

     if (n % 2 == 0 && n != 0) {
        prod /= maxi;
    }

    return prod;
}

int main() {
    vector<int> vec = {2, 1, -1, 7, 9, 0};
    cout << minprodut(vec) << endl;
    return 0;
}
*/

//k max sum of 2 array
/*

// A simple C++ program to find N maximum
// combinations from two arrays,
#include <bits/stdc++.h>
using namespace std;

// function to display first N maximum sum
// combinations
void KMaxCombinations(int A[], int B[], 
					int N, int K)
{
	// max heap.
	priority_queue<int> pq;

	// insert all the possible combinations
	// in max heap.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			pq.push(A[i] + B[j]);

	// pop first N elements from max heap
	// and display them.
	int count = 0;
	while (count < K) {
		cout << pq.top() << endl;
		pq.pop();
		count++;
	}
}

// Driver Code.
int main()
{
	int A[] = { 4, 2, 5, 1 };
	int B[] = { 8, 0, 5, 3 };
	int N = sizeof(A) / sizeof(A[0]);
	int K = 3;

	// Function call
	KMaxCombinations(A, B, N, K);
	return 0;
}

 */