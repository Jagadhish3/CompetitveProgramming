#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int> q;
void topological(vector<int>& indegree,vector<pair<int,int>> vec,vector<int> graph[6]){
    for(int i=0;i<6;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<graph[curr].size();i++){
            int v = graph[curr][i];
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }

}

int main(){
    int n=6;
    vector<pair<int,int>> vec;
    vector<int> indegree(n);
    int edges;
    cin>>edges;
    vector<int> graph[n];
    for(int i=0;i<edges;i++){
        int v1,v2;
        cin>>v1>>v2;

        vec.push_back({v1,v2});
    }

    for(auto p:vec){
        graph[p.second].push_back(p.first);
        indegree[p.first]++;
    }

       topological(indegree,vec,graph);
    for(int i=0;i<6;i++){
        if(indegree[i]!=0){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;

}