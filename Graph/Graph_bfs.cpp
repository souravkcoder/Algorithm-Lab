#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_traversal(int n, vector<int>adj[] ){
    int vis[n+1]={0};
    vis[1]=1;
    queue<int>q;
    q.push(1);
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
    return bfs;




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
        vector<int>ans=bfs_traversal(n,adj);
        cout<<"BFS Traversal is : ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }



return 0;
}
