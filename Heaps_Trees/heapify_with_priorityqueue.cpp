#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
   priority_queue<int, vector<int>, greater<int>> mini;

   int minim = 1000;
   int n;
   cin>>n;
    int k;
    cin>>k;
   for(int i=0;i<n;i++){
    int ele;
    cin>>ele;
    mini.push(ele);
    if(mini.size()>n-k){
        minim = min(minim,mini.top());
        mini.pop();
    }
   }
   cout<<minim;
}