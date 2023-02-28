#include <bits/stdc++.h>
using namespace std;

int t=0;

void dfs_visit(vector<vector<int>>&vertex, vector<int>adj[],int u){

    t++;
    vertex[u][1]=t;
    vertex[u][0]=1;
    for(auto v:adj[u]){
        if(vertex[v][0]==0){
            vertex[v][2]=u;
            dfs_visit(vertex,adj,v);
        }

    }
    vertex[u][0]=2;
    t++;
    vertex[u][4]=t;



}

vector<vector<int>>dfs_traversal(int n,vector<int>adj[]){

    vector<vector<int>>vertex(n+1);
    for(int i=1; i<=n; i++)
    {
        vector<int>temp(5);
        temp[0]=0;          //color
        temp[1]=INT_MAX;    //distance
        temp[2]=-1;         //parent
        temp[3]=i;          //vertex
        temp[4]=INT_MAX;
        vertex[i]=temp;
    }

    for(int i=1;i<=n;i++){
        if(vertex[i][0]==0){
            dfs_visit(vertex,adj,i);
        }
    }
    return vertex;
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
        vector<vector<int>>ans=dfs_traversal(n,adj);
        cout<<"DFS Traversal is : ";
        for(auto it: ans){
          //  cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
          for (auto x: it) cout<<x<<" ";
          cout<<endl;
        }





return 0;
}
