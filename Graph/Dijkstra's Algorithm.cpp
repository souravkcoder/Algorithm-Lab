#include <bits/stdc++.h>
using namespace std;

vector<int>dijkstra_algo(int v, vector<vector<int>>adj[],int s){
     priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
     vector<int>dist(v);
     for(int i=0;i<v;i++){
        dist[i]=2e9;
     }
     dist[s]=0;
     pq.push({0,s});
     while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            for(auto it: adj[node]){
                int ewt=it[1];
                int adjNode=it[0];
                if(dis+ewt<dist[adjNode]){
                    dist[adjNode]=dis+ewt;
                    pq.push({dist[adjNode],adjNode});
                }
            }


     }
     return dist;

}

int main() {

 int n,m;
    cin>>n>>m;
    vector<vector<int>>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(v);
        temp.push_back(wt);
        adj[u].push_back(temp);
        //Comment the next line for directed graph
        vector<int>temp2;
        temp2.push_back(u);
        temp2.push_back(wt);
        adj[v].push_back(temp2);

    }
    int source=0;
    vector<int>ans=dijkstra_algo(n,adj,source);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }



return 0;
}
