#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, x;
    long long mod=1000000007;
    scanf("%d %d", &n, &x);
    vector<long long>v(n);
    for(i=0; i<n; i++)scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    vector<long long>prev(x+1, 0), curr(x+1);
    prev[0]=1;
    curr[0]=1;
    for(j=1; j<x+1; j++)
    {
        for(i=0; i<n; i++)
        {
            if(j-v[i] < 0){
                curr[j] += (prev[j])%mod;
            }
            else curr[j] += (curr[j-v[i]])%mod;
        }
        curr[j]=curr[j]%mod;
        prev[j] = curr[j];
    }
    cout << prev[x] << '\n';
}