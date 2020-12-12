#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, x;
    scanf("%d %d", &n, &x);
    vector<int>price(n), pages(n);
    for(i=0; i<n; i++)scanf("%d", &price[i]);
    for(i=0; i<n; i++)scanf("%d", &pages[i]);
    vector<long long>dp(x+1, 0), prev(x+1, 0);
    for(i=0; i<n; i++)
    {
        for(j=0; j<x+1; j++)
        {
            if(j-price[i]<0)dp[j]=prev[j];
            else{
                dp[j]=max(prev[j], pages[i] + prev[j-price[i]]);
            }
        }
        prev = dp;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}