#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;
vector<vector<ll>>g, rg;
vector<ll>dist, st, visited;
ll n, m, i, j, u, v;
void topsort(ll u)
{
    visited[u] = 1;
    for(auto v:g[u])if(!visited[v])topsort(v);
    st.push_back(u);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scanf("%lld %lld", &n, &m);
    g.assign(n+1, vector<ll>(0));
    rg.assign(n+1, vector<ll>(0));
    visited.assign(n+1, 0);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    dist.assign(n+1, 0);
    visited.assign(n+1, 0);
    topsort(1);
    if(find(st.begin(), st.end(), n) == st.end())
    {
        cout << 0 << '\n';
        return 0;
    }
    queue<ll>q;
    q.push(n);
    fill(visited.begin(), visited.end(), 0);
    visited[n] = 1;
    dist[n] = 1;
    for(auto u:st)
    {
        if(!visited[u])continue;
        else {
            for(auto v:rg[u])
            {
                visited[v] = 1;
                dist[v] += dist[u];
                dist[v] %= MOD;
            }
        }
    }
    cout << dist[1] << '\n';
}