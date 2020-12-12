#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define INF 1e18
int main()
{
    fast;
    ll n,m,i,j,u,v,w,flag,cost;
    cin >> n >> m;
    map<ll, vector<vector<ll>>>g;
    set<vector<ll>>pq;
    vector<ll>full(n+1, INF), disc(n+1, INF);
    for(i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    full[1] = 0; disc[1] = 0;
    pq.insert({0, 1, 0});
    pq.insert({0, 1, 1});
    while(!pq.empty())
    {
        
        auto top = *pq.begin();
        cost = top[0]; u = top[1]; flag = top[2];
        pq.erase(pq.begin());
        if(flag == 1)
        {
            if(full[u] < cost)continue;
        }
        else {
            if(disc[u] < cost)continue;
        }
        for(auto node:g[u])
        {
            
            v = node[0]; w = node[1];
            
            if (flag) 
            {
                if(full[v] > cost + w)
                {
                    full[v] = cost + w;
                    pq.insert({full[v], v, flag});
                }
                if(disc[v] > cost + w/2)
                {
                    disc[v] = cost + w/2;
                    pq.insert({disc[v], v, 0});
                }
            }
            else {
                if (disc[v] > cost + w)
                {
                    disc[v] = disc[u] + w;
                    pq.insert({disc[v], v, flag});
                }

            }
        }
    }
    cout << disc[n] << '\n'; 
}