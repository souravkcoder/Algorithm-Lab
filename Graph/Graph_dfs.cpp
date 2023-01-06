#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[],int vis[],vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(int i=0;i<adj[node].size();i++){
            int it=adj[node][i];
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int>dfs_traversal(int n, vector<int>adj[]){
    int vis[n+1]={0};
    int start=1;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

int main() {

 int n,m;
        cin>>n>>m;
        vector<int>adj[n+1];
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            //Comment the next line for directed graph
            adj[v].push_back(u);
        }
        vector<int>ans=dfs_traversal(n,adj);
        cout<<"DFS Traversal is : ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }





return 0;
}
