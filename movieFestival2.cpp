#include <bits/stdc++.h>
using namespace std;
bool comp(const vector<long long>& v1, const vector<long long>& v2) 
{
    return v1[1] < v2[1];
}
int main()
{
    int n, k, i, j=1, cnt=1;
    scanf("%d %d", &n, &k);
    vector<vector<long long>>v;
    multiset<long long>s;
    for(i=0; i<n; i++)
    {
        vector<long long>temp(2);
        for(j=0; j<2; j++) scanf("%lld", &temp[j]);
        v.push_back(temp);
    }
    if(k==n)
    {
        cout << n << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    for(i=0; i<n; i++)
    {
        if(s.size() == 0) s.insert(v[i][1]);
        else{
            if(*s.begin() <= v[i][0])
            {
                auto itr=upper_bound(s.begin(), s.end(), v[i][0]);
                itr--;
                s.erase(itr);
                s.insert(itr, v[i][1]);
                cnt++;
            }
            else if(s.size()<k){
                cnt++;
                s.insert(v[i][1]);
            }
        }
    }
    cout << cnt << '\n';
}
