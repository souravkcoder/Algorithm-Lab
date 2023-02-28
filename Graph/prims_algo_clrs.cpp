#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prims_algo(int v,vector<vector<int>>adj[],int s )
{

    vector<vector<int>>vertex(v+1);
    for(int i=1; i<=v; i++)
    {
         vertex[i][0]=INT_MAX;
         vertex[i][1]=-1;
         vertex[i][2]=i;

    }

    vertex[s][0]=0;
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;

    for(int i=1; i<=v; i++)
    {
        pq.push({vertex[i][0],vertex[i][1],vertex[i][2]});
    }

    // pq.push({vertex[s][0],vertex[s][1],vertex[s][2]});

    vector<int>vis(v+1,0);
    while(!pq.empty())
    {
        auto itt=pq.top();
        pq.pop();
        int node=itt[2];
        int key=itt[0];
        int pred=itt[1];
        vis[node]=1;
        for(auto it: adj[node])
        {
            int v=it[0];
            int w=it[1];
            if(vis[v]==0 && w<vertex[v][0])
            {
                vertex[v][0]=w;
                vertex[v][1]=node;
                pq.push({vertex[v][0],vertex[v][1],vertex[v][2]});
            }
        }
    }
    return vertex;
}


int main()
{
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
    vector<vector<int>> ans=prims_algo(n,adj,1);
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }

    return 0;
}
