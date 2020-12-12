#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j=0, k;
    long long s=0, e=1000000000000000, mid, sum=0, ans;
    scanf("%d %d", &n, &k);
    vector<long long>v(n);
    for(i=0; i<n; i++)scanf("%lld", &v[i]);
    ans = *max_element(v.begin(), v.end());
    while(s<=e)
    {
        j=1; sum=0;
        mid = (s+e)/2;
        for(i=0; i<n; i++)
        {
            if(v[i] > mid)
            {
                j = k+1;
                break;
            }
            if(sum+v[i] > mid){
                j++;
                sum=v[i];
            }
            else{
                sum += v[i];
            }
        }
        if(j==k) ans=mid;
        if(j > k)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout << ans << '\n';
    
}
