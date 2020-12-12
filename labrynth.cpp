#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, x, y;
    string ans="";
    int a[2], b[2];
    scanf("%d %d", &n, &m);
    vector<string>v(n);
    for(i=0; i<n; i++)cin >> v[i];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(v[i][j] == 'A')
            {
                a[0] = i;
                a[1] = j;
            }
            if(v[i][j] == 'B')
            {
                b[0] = i;
                b[1] = j;
            }
        }
    vector<vector<int>>dist(n, vector<int>(m, n*m+1)), visited(n, vector<int>(m, 0));
    dist[b[0]][b[1]] = 0;
    visited[b[0]][b[1]] = 1;
    queue<pair<int, int>>q;
    q.push(make_pair(b[0], b[1]));
    while(q.size())
    {
        x = q.front().first; y = q.front().second;
        q.pop();
        auto l = make_pair(x, y-1);
        auto r = make_pair(x, y+1);
        auto u = make_pair(x-1, y);
        auto d = make_pair(x+1, y);
        for(auto node:{l,r,u,d})
        {
            auto x1 = node.first, y1 = node.second;
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && v[x1][y1] != '#')
            {
                if(visited[x1][y1])continue;
                else {
                    visited[x1][y1] = 1;
                    dist[x1][y1] = min(dist[x1][y1], dist[x][y]+1);
                    q.push(make_pair(x1, y1));
                }
            }
        }
    }
    if(!visited[a[0]][a[1]]) printf("NO\n");
    else {
        printf("YES\n");
        printf("%d\n", dist[a[0]][a[1]]);
        auto curr = dist[a[0]][a[1]];
        x = a[0]; y = a[1];
        while(curr)
        {
            auto l = make_pair(x, y-1);
            auto r = make_pair(x, y+1);
            auto u = make_pair(x-1, y);
            auto d = make_pair(x+1, y);
            for(auto node:{l,r,u,d})
            {
                auto x1 = node.first, y1 = node.second;
                if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && v[x1][y1] != '#')
                {
                    if(dist[x1][y1] == curr-1)
                    {
                        curr--;
                        if(node == l)
                        {
                            y--;ans += 'L';
                        }
                        else if(node == r)
                        {
                            y++; ans += 'R';
                        }
                        else if(node == u)
                        {
                            x--;ans += 'U';
                        }
                        else 
                        {
                            x++; ans += 'D';
                        }
                        break;
                    }
                }
            }
        }
    }   
    cout << ans << '\n';
}