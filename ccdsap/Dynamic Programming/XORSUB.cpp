#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    test {
        int n, k;
        cin>>n>>k;
        int a[n];
        loop(i, 0, n)
            cin>>a[i];

        int dp[1001][1024] = {};
        dp[0][0] = 1;
        dp[0][a[0]] = 1;
        loop(i, 1, n) {
            loop(j, 0, 1024) {
                dp[i][j] = dp[i-1][j] | dp[i-1][j ^ a[i]];
            }
        }
        int maxi = 0;
        loop(j, 0, 1024) {
            if(dp[n-1][j] == 1)
            maxi = max(maxi, (j ^ k));
        }

        // loop(i, 0, n) {
        //     loop(j, 0, 10) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        cout<<maxi<<"\n";
    }
    return 0;
}