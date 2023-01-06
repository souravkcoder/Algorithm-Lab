#include <bits/stdc++.h>
using namespace std;
//My Macros
#define ll long long
#define nl cout<<"\n"; //For new Line

#define fastio \
ios::sync_with_stdio(0); \
cin.tie(0); //For Fast Input Output

#define setp(s)\
cout<<setprecision(s)<<fixed; //Setting Floating Point Precision

int main()
{

    long long tc=1;
    // cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;
        int adj[n+1][n+1];
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
            //Comment the next line for directed graph
            adj[v][u]=1;
        }

        for(int i=1; i<=n; i++)
        {
            cout<<"Adj of " <<i<<" : ";
            for(int j=1; j<=n; j++)
            {
                if(adj[i][j]==1) cout<<j<<" ";
            }
            cout<<endl;
        }


    }



    return 0;
}
