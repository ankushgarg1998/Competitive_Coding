#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

lli n, l, r;
lli z=0, o=0, t=0;
lli dp[200010][3];

lli func(int i, int x) {
    if(i == n) {
        if(x == 0) {
            return 1;
        } else
            return 0;
    }

    if(dp[i][x] != -1)
        return dp[i][x];

    lli ret = z * func(i+1, x);
    ret %= MOD;
    ret += (o * func(i+1, (x+1)%3));
    ret %= MOD;
    ret += (t * func(i+1, (x+2)%3));
    ret %= MOD;
    return dp[i][x] = ret;
}

int main() {
    cin>>n>>l>>r;
    loop(i, 0, n+1) {
        loop(j, 0, 3) {
            dp[i][j] = -1;
        }
    }
    if(r-l > 10) {
        lli L = l;
        if(l%3 == 1) {
            L = l+2;
            ++o; ++t;
        } else if(l%3 == 2) {
            L = l+1;
            ++t;
        }

        lli R = r;
        ++z;
        if(r%3 == 1) {
            R = r-1;
            ++o;
        } else if(r%3 == 2) {
            R = r-2;
            ++t; ++o;
        }

        lli val = (R/3) - (L/3);
        z += val;
        o += val;
        t += val;
    } else {
        loop(i, l, r+1) {
            if(i%3 == 0) {
                ++z;
            } else if(i%3 == 1) {
                ++o;
            }else {
                ++t;
            }
        }
    }
    cout<<func(0, 0)<<"\n";
    return 0;
}