#include <bits/stdc++.h>
using namespace std;
vector<string>maze;
int X, Y;
void solve(int i, int j, vector<vector<int>>& dist, vector<vector<int>>visited)
{
    dist[i][j] = 0;
    visited[i][j] = 1;
    queue<pair<int, int>>q;
    q.push(make_pair(i, j));
    while(q.size())
    {
        auto x = q.front().first; auto y = q.front().second;
        q.pop();
        auto l = make_pair(x, y-1);
        auto r = make_pair(x, y+1);
        auto u = make_pair(x-1, y);
        auto d = make_pair(x+1, y);
        for(auto node:{l,r,u,d})
        {
            auto x1 = node.first, y1 = node.second;
            if(x1 >= 0 && x1 < dist.size() && y1 >= 0 && y1 < dist[0].size() && maze[x1][y1] != '#' && maze[x1][y1] != 'M')
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
}
void trace(int x, int y, vector<vector<int>>& dist)
{
    string ans = "";
    while(x != X || y != Y)
    {
        auto l = make_pair(x, y-1);
        auto r = make_pair(x, y+1);
        auto u = make_pair(x-1, y);
        auto d = make_pair(x+1, y);
        for(auto node:{l,r,u,d})
            {
                auto x1 = node.first, y1 = node.second;
                if(x1 >= 0 && x1 < dist.size() && y1 >= 0 && y1 < dist[0].size() && maze[x1][y1] != '#' && maze[x1][y1] != 'M' && dist[x][y] > dist[x1][y1])
                {
                    x = x1; y = y1;
                    if(node == l) ans += 'R';
                    else if(node == r) ans += 'L';
                    else if (node == u) ans += 'D';
                    else ans += 'U';
                    break;
                }
            }
    }
    printf("YES\n%d\n", ans.size());
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
int main()
{
    int n,m,i,j;
    scanf("%d %d", &n, &m);
    maze.assign(n, "");
    for(i=0; i<n; i++);
    for(i=0; i<n; i++)
    {
        string temp;
        cin >> temp;
        maze[i] = temp;
    }
    vector<vector<int>>visited(n, vector<int>(m, 0)), dist1(n, vector<int>(m, n*m+1)), dist2(n, vector<int>(m, n*m+1));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(maze[i][j] == 'M')
            {
                solve(i, j, dist1, visited);

            }
            else if(maze[i][j] == 'A')
            {
                X = i; Y = j;
                solve(i, j, dist2, visited);
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(dist2[i][0] < dist1[i][0])
        {
            trace(i, 0, dist2);
            return 0;
        }
        else if(dist2[i][m-1] < dist1[i][m-1])
        {
            trace(i, m-1, dist2);
            return 0;
        }
    }
    for(j=0; j<m; j++)
    {
        if(dist2[0][j] < dist1[0][j])
        {
            trace(0, j, dist2);
            return 0;
        }
        else if(dist2[n-1][j] < dist1[n-1][j])
        {
            trace(n-1, j, dist2);
            return 0;
        }
    }
    printf("NO");
}