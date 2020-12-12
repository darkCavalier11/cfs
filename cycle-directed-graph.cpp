#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,u,v,s=-1,e=-1;
vector<vector<ll>>g;
vector<ll>visited, parent, ans;
void dfs(ll u, ll p)
{
    visited[u] = 1;
    parent[u] = p;
    for(auto v:g[u])
    {
        if (visited[v] == 2)continue;
        else if(visited[v] == 0)dfs(v,u);
        else if (visited[v] == 1) 
        {
            s = u;
            e = v;
        }
    } 
    visited[u] = 2;
}
int main()
{
    cin >> n >> m;
    g.assign(n+1, vector<ll>(0));
    for(i=0; i<m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    visited.assign(n+1, 0);
    parent.assign(n+1, -1);
    visited.assign(n+1, 0);
    for(i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1);
        }
    }
    if(s==-1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    else {
        ans.push_back(e);
        while(e!=s)
        {
            ans.push_back(s);
            s = parent[s];
        }
        ans.push_back(e);
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto x:ans)cout << x << ' ';
}