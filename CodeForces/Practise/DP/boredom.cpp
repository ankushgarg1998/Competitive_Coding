#include<iostream>
#include<vector>
using namespace std;

int main()
    {
    long int n, x, maxx=0;
    cin>>n;
    vector<long long int> v(100001, 0), dp(100001, 0);
    for(int i=0; i<n; i++)
        {
        cin>>x;
        maxx = max(maxx, x);
        ++v[x];
        }
    dp[1] = v[1];
    dp[2] = max(v[1], v[2]*2);
    for(int i=3; i<=maxx; i++)
        {
        dp[i] = max(dp[i-1], dp[i-2]+(v[i]*i));
        }
    cout<<dp[maxx]<<"\n";
    return 0;
    }