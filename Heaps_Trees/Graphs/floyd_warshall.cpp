#include<bits/stdc++.h>
using namespace std;


void floyd(vector<vector<int>> &graph,int v){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(graph[i][k]!=INT16_MAX && graph[k][j]!=INT16_MAX){
                    if(graph[i][j] > graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    int v;
    cin>>v;
    vector<vector<int>> graph(v,vector<int>(v,INT16_MIN));
    int edges;
    cin>>edges;
        for(int j=0;j<edges;j++){
            int v1,v2,wt;
            cin>>v1>>v2>>wt;
            graph[v1][v2]=wt;
    }
    floyd(graph,v);
    cout<<graph[1][3];

}