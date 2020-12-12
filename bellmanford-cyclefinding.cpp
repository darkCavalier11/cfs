#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
int main()
{
    // initialize
    ll n,m,i,j,u,v,w,x;
    cin >> n >> m;
    vector<vector<ll>>g;
    vector<ll>dist(n+1, INF), parent(n+1), ans;
    for(i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u,v,w});
    }
    dist[0] = 0;
    for(i=0; i<n-1; i++)
    {
        x = -1;
        for(auto e:g)
        {
            u = e[0]; v = e[1]; w = e[2];
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }
    if(x==-1)cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(i=0; i<n; i++)
        {
            x = parent[x];
        }
        ans.push_back(x);
        x = parent[x];
        while(x != ans[0])
        {
            ans.push_back(x);
            x = parent[x];
        }
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    for(auto x:ans)cout << x << ' ';
}