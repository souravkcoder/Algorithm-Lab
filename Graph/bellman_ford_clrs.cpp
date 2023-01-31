#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(int v,vector<vector<int>>&vertex,int s){

    for(int i=1;i<=v;i++){
        vector<int>temp(2);
        temp[0]=INT_MAX; //distance
        temp[1]=-1;         //parent
        vertex[i]=temp;
    }
    vertex[s][0]=0;

}

void relax(vector<vector<int>>&vertex,int u,int v,int w){
    if(vertex[u][0]!=INT_MAX && (vertex[v][0]>(vertex[u][0]+w))){
        vertex[v][0]=vertex[u][0]+w;
        vertex[v][1]=u;
    }
}

bool bellman_ford(int v,vector<vector<int>>&vertex, vector<vector<int>>&edges,int s ){

    initialize_single_source(v,vertex,s);


    for(int i=1; i<=(v-1);i++){

            for(auto it : edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                relax(vertex,u,v,w);

            }
    }


    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        if(vertex[v][0]>vertex[u][0]+w){
            return false;
        }
    }
    return true;

}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vertex(n+1);
    vector<vector<int>>edges;
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
    }
    int source=1;
    bool ans=bellman_ford(n,vertex,edges,source);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }




return 0;
}
