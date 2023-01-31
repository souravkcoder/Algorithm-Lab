#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(int v,vector<vector<int>>&vertex,int s)
{
    //sob vertex er distance part a infinite r parent a -1 rakhlam
    for(int i=1; i<=v; i++)
    {
        vector<int>temp(3);
        temp[0]=INT_MAX; //distance
        temp[1]=-1;       //parent
        temp[2]=i;          //vertex
        vertex[i]=temp;     //i tomo vertex a rekhe dilam
    }
    vertex[s][0]=0; //source to source distance zero

}



void dijkstra_algo(int n,vector<vector<int>>&vertex, vector<vector<int>>adj[],int s)
{

    initialize_single_source(n,vertex,s);
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
    //full vertex ta ke push korlam prority queue a
    for(int i=1; i<=n; i++)
    {
        pq.push({vertex[i][0],vertex[i][1],vertex[i][2]});
    }
    while(!pq.empty())
    {
        auto itt=pq.top();
        pq.pop();
        int dis=itt[0];
        int pred=itt[1];
        int u=itt[2];

        for(auto it : adj[u])
        {
            int v=it[0];
            int  w=it[1];
            if(vertex[u][0]!=INT_MAX && (vertex[v][0]>(vertex[u][0]+w))) //vertex[u][0] te infinte chilo, er sathe kichu jog korle ta int a rakha jabe na, tai int_max jokhon thakbe na tokhon tulona korchi [vertex[u][0]!=INT_MAX]-ei line use kore
            {
                vertex[v][0]=vertex[u][0]+w;
                vertex[v][1]=u;
                pq.push({vertex[v][0],vertex[v][1],vertex[v][2]});
            }
        }
    }


}



int main()
{

    int n,m;
    cin>>n>>m;
    vector<vector<int>>vertex(n+1);
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
    int source=1;
    dijkstra_algo(n,vertex,adj,source);
    for(int i=1; i<=n; i++)
    {
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<" "<<vertex[i][2]<<endl;
    }



    return 0;
}
