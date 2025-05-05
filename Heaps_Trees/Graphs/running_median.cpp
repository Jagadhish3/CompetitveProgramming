#include<bits/stdc++.h>
using namespace std;

vector<double> runningMedian(vector<int> a) {
    vector<double> vec;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    for(int num:a){
        if(maxheap.empty() || num<=maxheap.top()){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }
        
        if(maxheap.size()> minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        
        if(minheap.size()==maxheap.size()){
            vec.push_back((minheap.top()+maxheap.top())/2.0);
        }else{
            vec.push_back(maxheap.top());
        }
    }
    return vec;
}

int main(){
    int n=6;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);       
    }
vector<double> res = runningMedian(vec);
for(auto num:res){
    cout<<num<<" ";
}
}