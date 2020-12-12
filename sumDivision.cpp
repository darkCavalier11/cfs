#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    long long cnt=0, curr=0, temp;
    scanf("%d", &n);
    vector<long long>v(n);
    for(i=0; i<n; i++) scanf("%lld", &v[i]);
    map<long long, long long>sum;
    for(i=0; i<n; i++)
    {
        curr += v[i]; 
        temp = (curr%n+n)%n;
        if(temp == 0)cnt++;
        cnt += sum[temp];
        sum[temp]++;
    }
    printf("%lld\n", cnt);
}