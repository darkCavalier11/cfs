#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i, j;
    long long l=0, r=0;
    scanf("%d %d", &n, &k);
    vector<long long>v(n), sub(k);
    for(i=0;i<n;i++) scanf("%lld", &v[i]);
    if(k==1)
    {
        for(i=0; i<n; i++)cout << 0 << ' ';
        return 0;
    }
    multiset<long long>mini, maxi;
    for(i=0; i<k; i++)sub[i]=v[i];
    sort(sub.begin(), sub.end());
    for(i=0; i<k/2; i++)mini.insert(sub[i]);
    for(i=k/2; i<k; i++) maxi.insert(sub[i]);
    for(auto it=mini.begin(); it!=mini.end(); it++) l+=*it;
    for(auto it=maxi.begin(); it!=maxi.end(); it++) r+=*it;
    if(k%2) cout << r-l-*maxi.begin() << ' ';
    else cout << r-l << ' '; 
    j=0;
    for(i=k; i<n; i++)
    {
        if(v[j] < *maxi.begin())
        {
            mini.erase(mini.find(v[j]));
            l -= v[j];
        }
        else 
        {
            maxi.erase(maxi.find(v[j]));
            r -= v[j];
        }
        j++;
        if(mini.size() < k/2)
        {
            if(v[i] < *maxi.begin())
            {
                mini.insert(v[i]);
                l+=v[i];
            }
            else{
                mini.insert(*maxi.begin());
                l+=*maxi.begin();
                r-=*maxi.begin();
                maxi.erase(maxi.begin());
                maxi.insert(v[i]);
                r+=v[i];
            }
        }
        else if (maxi.size() < k-k/2){
            if(v[i] >= *--mini.end())
            {
                maxi.insert(v[i]);
                r+=v[i];
            }
            else{
                maxi.insert(*--mini.end());
                l-=*--mini.end();
                r+=*--mini.end();
                mini.erase(*--mini.end());
                mini.insert(v[i]);
                l+=v[i];
            }
        }
        if(k%2) cout << r-l-*maxi.begin() << ' ';
        else cout << r-l << ' '; 
    }
}
