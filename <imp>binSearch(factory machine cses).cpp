#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, i, j;
    ll t, lo=0, hi=10e18+7, ans, mid;
    scanf("%d %lld", &n, &t);
    vector<ll> v(n);
    for(i=0; i<n; i++)
    {
        scanf("%lld", &v[i]);
    }
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        ll temp = 0;
        for(i=0; i<n; i++)
        {
            temp += mid/v[i];
            if(temp >= t) break;
        }
        if(temp >= t)
        {
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    printf("%lld", ans);
}