#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>>&edges,int s ){
    vector<int>dist(v,1e8);
    dist[s]=0;
    //loops for relaxing vertex-1 times
    for(int i=0;i<v-1;i++){
       for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
        }
       }
    }

    //If negative cycle exist,returning an array having only -1
       for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
            return {-1};
        }
       }
    return dist;


}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
    }
    int source=0;
    vector<int>ans=bellman_ford(n,edges,source);
    for(auto it : ans){
        cout<<it<<" ";
    }





return 0;
}
