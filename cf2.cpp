//g++  5.4.0
 
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e5+10;
vector<int> g[nax] , rg[nax] ,vis(nax,0) , dist(nax,0) , par(nax,0);
stack<int> s;
 
void toposort(int v)
{
    vis[v] = 1;
    for( auto &i : g[v] )
    {
        if( !vis[i] )
        {
            dist[i] = dist[v]+1;
            par[i] = v;
            toposort( i );
        }
    }
    s.push( v );
    return ;
}
signed main()
{
    fast;
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u,v;
        cin >> u>> v;
        g[u].pb(v);
        rg[v].pb(u);
    }
    toposort( 1 );
    if( !vis[n] ) return cout << "IMPOSSIBLE\n" , 0;
    else
    {
        while(!s.empty())
        {
            cout << s.top() << ' ';
            s.pop();
        }
        cout << endl;
        while( !s.empty() )
        {
            cout << "k" << endl;
            int v = s.top();
            s.pop();
            for(auto &i:rg[v] )
            {
                if( dist[v] < dist[i]+1 )
                {
                    par[v] = i;
                    dist[v] = dist[i] + 1;
                }
            }
        }
        
        cout << dist[n]+1 << "\n";
        stack<int> ans;
        ans.push(n);
        int pv = par[n] ;
        while( pv != 0 )
        {
            ans.push( pv );
            pv = par[pv];
        }
        while( !ans.empty() )
        {
            cout << ans.top() << " " ;
            ans.pop();
        }
    }
}
