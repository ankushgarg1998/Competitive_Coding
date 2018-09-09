#include<iostream>
#include<algorithm>
#include<climits>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>=b; i--)
using namespace std;

int dp[1010];

int rec(int n) {
    if(dp[n] != -1)
        return dp[n];

    int x = INT_MAX;
    loop(i, 1, (n/2 + 1)) {
        x = min(x, (rec(i) + rec(n-i)));
    }
    return dp[n] = x;
}

int main() {
    test {
        int n;
        cin>>n;
        int h[n], k[n];

        loop(i, 0, 1001)
            dp[i] = -1;
        loop(i, 0, n)
            cin>>h[i];
        loop(i, 0, n) {
            cin>>k[i];
            dp[k[i]] = 1;
        }

        loop(i, 0, 1001) {
            if(dp[i] == 1)
                break;
            dp[i] = 1000;
        }
        dp[0] = 0;

        lli ans = 0;
        loop(i, 0, n) {
            // cout<<rec(2*h[i])<<" ";
            ans += rec(2*h[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}