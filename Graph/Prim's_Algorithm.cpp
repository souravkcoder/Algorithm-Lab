#include <bits/stdc++.h>
using namespace std;

int prims_algo(int v,vector<vector<int>>adj[] )
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>vis(v,0);

    pq.push({0,0});
    int sum=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node]==1) continue;
        //add it to the mst
        vis[node]=1;
        sum+=wt;
        for(auto it : adj[node])
        {
            int adjNode=it[0];
            int adjNodeWeight= it[1];
            if(!vis[adjNode])
            {
                pq.push({adjNodeWeight,adjNode});
            }

        }
    }
    return sum;
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
    int ans=prims_algo(n,adj);
    cout<<ans<<endl;




    return 0;
}
