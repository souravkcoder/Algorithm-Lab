#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>size;
    vector<int>parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find_ultimate_parent(int node){
        if(node==parent[node]) return node;
        return parent[node]=find_ultimate_parent(parent[node]);
    }

    void union_by_size(int u, int v){
        int ultimate_par_u=find_ultimate_parent(u);
        int ultimate_par_v=find_ultimate_parent(v);
        if(ultimate_par_u==ultimate_par_v) return;
         if(size[ultimate_par_u]<size[ultimate_par_v]){
            parent[ultimate_par_u]=ultimate_par_v;
            size[ultimate_par_v]+=size[ultimate_par_u];
         }
         else {
             parent[ultimate_par_v]=ultimate_par_u;
            size[ultimate_par_u]+=size[ultimate_par_v];
         }

    }


};


vector<vector<int>> kruskal_algo(int n, vector<vector<int>>&edges){
    vector<vector<int>>A;
    DisjointSet ds(n);
    sort(edges.begin(),edges.end());
    for(auto it: edges){
        int w=it[0];
        int u=it[1];
        int v=it[2];
        if(ds.find_ultimate_parent(u)!=ds.find_ultimate_parent(v)){
            vector<int>temp;
            temp.push_back(u);
            temp.push_back(v);
            temp.push_back(w);
            A.push_back(temp);
            ds.union_by_size(u,v);
        }
    }
    return A;


}


int main() {
     int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(wt);
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);

    }
    vector<vector<int>> ans=kruskal_algo(n,edges);
    cout<<"Ans is : "<<endl;
    for(auto it: ans){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }



return 0;
}
