#include <bits/stdc++.h>
using namespace std;




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

    for(int i=0; i<n; i++)
    {
        cout<<"Adjacency list of "<<i<<": ";
        for(auto it : adj[i])
        {
            cout<<it[0]<<" "<<it[1]<<" ";
        }
        cout<<endl;
    }




    return 0;
}
