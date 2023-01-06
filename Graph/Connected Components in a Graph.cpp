#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(int n,int start, vector<int>adj[],int vis[] ){
    vis[start]=1;
    queue<int>q;
    q.push(start);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int i=0;i<adj[node].size();i++){
                int it=adj[node][i];
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }




}

int main()
{
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
    int vis[n+1]={0};
    int count=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs_traversal(n,i,adj,vis);
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
