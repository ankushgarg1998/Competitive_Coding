#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
using namespace std;

int main() {
    test {
        lli n;
        cin>>n;
        vector<lli> a(n), twos(n, 0), threes(n, 0);
        loop(i, 0, n)
            cin>>a[i];
        sort(a.begin(), a.end());

        lli ans = 1;
        for(int i=0; i<n-2; i += 2) {
            if(a[i+1] == a[i+2]) {
                if(a[i] == a[i+1] || a[i+2] == a[i+3]) {
                    threes[i] = a[i+1];
                } else {
                    twos[i] = a[i+1];
                }
            }
        }

        lli q = 3, prev = -1;
        bool col = true;
        for(int i=0; i<n-2; i += 2) {
            if(twos[i] != 0) {
                ans *= 2;
                ans %= MOD;
            }
            if(threes[i] != 0) {
                if(threes[i] == prev) {
                    q += 2;
                    // cout<<i<<" "<<col<<" ";
                    if(threes[i+2] != prev) {
                        if(a[i+2] != a[i+3] && col == false)
                            q -= 1;
                    }
                    ans *= q;
                    ans %= MOD;
                } else {
                    q = 3;
                    prev = threes[i];
                    if(a[i] != a[i+1]) {
                        col = false;
                    } else
                        col = true;
                    ans *= q;
                    ans %= MOD;
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;   
}