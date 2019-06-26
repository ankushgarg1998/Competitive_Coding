#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    string s[n];
    int f[n][m], g[n][m];
    loop(i, 0, n)
        cin>>s[i];
    loop(j, 0, m) {
        loopr(i, n-1, 0) {
            if(i == n-1)
                g[i][j] = s[i][j] - '0';
            else
                g[i][j] = (s[i][j] == '0'? 0: g[i+1][j]+1);
        }
    }
    lli ans = 0;
    loop(i, 0, n) {
        loop(j, 0, m) {
            if(j == 0)
                f[i][j] = s[i][j] - '0';
            else
                f[i][j] = min(f[i][j-1]+1, g[i][j]);
            ans += f[i][j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}