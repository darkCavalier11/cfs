#include <bits/stdc++.h>
using namespace std;
int main()
{
    // dp[i][x] = no of ways to pick only using first i coins
    int n, x, mod=1000000007, i, j;
    scanf("%d %d", &n, &x);
    vector<int>v(n), curr(x+1, 0), prev(x+1, 0);
    curr[0]=1;prev[0]=1;
    for(i=0; i<n; i++)scanf("%lld", &v[i]);
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=x; j++)
        {
            curr[j]=prev[j]%mod;
            if(j-v[i-1]>=0)curr[j]+=curr[j-v[i-1]]%mod;
        }
        prev=curr;

    }
    cout << curr[x]%mod << '\n';
}