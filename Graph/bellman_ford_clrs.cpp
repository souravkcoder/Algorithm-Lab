#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(int v,vector<vector<int>>&vertex,int s){
    //sob vertex er distance part a infinite r parent a -1 rakhlam
    for(int i=1;i<=v;i++){
        vector<int>temp(2);
        temp[0]=INT_MAX; //distance
        temp[1]=-1;       //parent
        vertex[i]=temp;     //i tomo vertex a rekhe dilam
    }
    vertex[s][0]=0; //source to source distance zero

}

void relax(vector<vector<int>>&vertex,int u,int v,int w){
    if(vertex[u][0]!=INT_MAX && (vertex[v][0]>(vertex[u][0]+w))) //vertex[u][0] te infinte chilo, er sathe kichu jog korle ta int a rakha jabe na, tai int_max jokhon thakbe na tokhon tulona korchi [vertex[u][0]!=INT_MAX]-ei line use kore
    {
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

//Negative cycle ache kina check korchi
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
    vector<vector<int>>edges; //edge store korchi
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
    if(ans){
        for(int i=1;i<=n;i++){
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }
    }
    else cout<<"Negative Cycle Exist.";





return 0;
}
