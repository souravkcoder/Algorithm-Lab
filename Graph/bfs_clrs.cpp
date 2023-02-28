#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>bfs_traversal(int n, vector<int>adj[],int s ){

    vector<vector<int>>vertex(n+1);
    for(int i=1; i<=n; i++)
    {
        vector<int>temp(4);
        temp[0]=0;          //color 0-white, 1-gray , 2-black
        temp[1]=INT_MAX;    //distance
        temp[2]=-1;         //parent
        temp[3]=i;          //vertex
        vertex[i]=temp;
    }

    vertex[s][0]=1;
    vertex[s][1]=0;
    vertex[s][2]=-1;

    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v: adj[u]){
            if(vertex[v][0]==0){
               vertex[v][0]=1;
               vertex[v][1]=vertex[u][1]+1;
               vertex[v][2]=u;
               q.push(v);
            }
        }
        vertex[u][0]=2;
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
        vector<vector<int>>ans=bfs_traversal(n,adj,1);
        cout<<"BFS Traversal is : ";
        for(auto it: ans){
          //  cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
          for (auto x: it) cout<<x<<" ";
          cout<<endl;
        }



return 0;
}
