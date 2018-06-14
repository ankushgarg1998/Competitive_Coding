#include<iostream>
#include<cstring>
#define MOD 1000003
using namespace std;

int t, n, k, dp[101][2][101];

int f(int i, int prev, int count)
    {
    if(i == n)
        {
        if(k == count)
            return 1;
        else
            return 0;
        }
    
    if(dp[i][prev][count] != -1)
        return dp[i][prev][count];

    int ans = 0;

    if(prev == 1)
        ans += f(i+1, 1, count+1);
    else
        ans += f(i+1, 1, count);

    ans %= MOD;
    ans += f(i+1, 0, count);
    ans %= MOD;

    return dp[i][prev][count] = ans;
    }

int main()
    {
    cin>>t;
    while(t--)
        {
        memset(dp, -1, sizeof(dp));
        cin>>n>>k;
        cout<<(f(1, 0, 0) + f(1, 1, 0))%MOD<<"\n";
        }
    return 0;
    }