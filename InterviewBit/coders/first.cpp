#include <bits/stdc++.h>
#define MOD 1000000007
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int res = 1;

map<int, int> m;

int solve(int A) {
    if(A < 4) {
        return 1;
    }
    else if(m[A] == 0) {
        // cout<<A<<
        int ans = 1;
        int sq = sqrt(A);
        for(int i=2; i<=sq; i++) {
            if(i == sq) {
                if(sq*sq == A) {
                ans *= sq;
                ans %= MOD;
                ans *= solve(sq);
                ans %= MOD;
                break;
                }
            }
            if(A%i == 0) {
                ans *= i;
                ans %= MOD;
                ans *= (solve(i));
                ans %= MOD;
                ans *= (A/i);
                ans %= MOD;
                ans *= (solve(A/i));
                ans %= MOD;
            }
        }
        return m[A] = ans;
    } else
        return m[A];
}


void f(int n) {
    loop(i, 1, n) {
        if(n%i == 0) {
        res = res*i;
        res %= MOD;
        f(i);
        }
    }
}

int main() {
    int n;
    cin>>n;
    f(n);
    cout<<res%MOD;
}