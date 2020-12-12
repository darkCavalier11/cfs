#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7, INF = 1e18;
vector<vector<ll>>g, rg;
map<vector<ll>, ll>wt;
vector<ll>dist, st, visited, routes, cost;
ll n, m, i, j, u, v, w, cnt=0, mr=INF, mx=0, minCost;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scanf("%lld %lld", &n, &m);
    g.assign(n+1, vector<ll>(0));
    rg.assign(n+1, vector<ll>(0));
    visited.assign(n+1, 0);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(v);
        rg[v].push_back(u);
        if(wt[{u, v}] == 0)wt[{u,v}] = w;
        else wt[{u, v}] = min(wt[{u, v}], w);
    }
    dist.assign(n+1, INF);
    cost.assign(n+1, 0);
    dist[1] = 0;
    visited.assign(n+1, 0);
    // dijkstra
    set<vector<ll>>pq;
    pq.insert({0, 1});
    while(!pq.empty())
    {
        auto node = *pq.begin();
        u = node[1]; w = node[0];
        pq.erase(pq.begin());
        for(auto v:g[u])
        {
            auto cost = wt[{u, v}];
            if (dist[v] > w + cost)
            {
                dist[v] = w + cost;
                pq.insert({w+cost, v});
            }
        }
    }
    minCost = dist[n];
    // routes
    routes.assign(n+1, 0);
    routes[1] = 1;
    queue<ll>q;
    q.push(1);
    cost[1] = minCost;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(cost[u] < 0)continue;
        for(auto v:g[u])
        {
            routes[v] += routes[u];
            routes[v] %= MOD;
            cost[v] = cost[u]-wt[{u, v}];
            q.push(v);
        }
    }
    for(auto x:routes)cout << x << ' ';
}