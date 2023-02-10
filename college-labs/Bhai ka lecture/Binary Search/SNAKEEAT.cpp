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
    FastIO
    test {
        int n, q;
        cin>>n>>q;
        li a[n], b[n+1];
        loop(i, 0, n) {
            cin>>a[i];
        }
        sort(a, a+n);
        b[n] = 0;
        loopr(i, n-1, 0)
            b[i] = b[i+1] + a[i];

        while(q--) {
            li x;
            cin>>x;
            int f=0, l=n-1, ans=n;
            while(f<=l) {
                int m = (f+l)/2;
                if(a[m] >= x) {
                    ans = m;
                    l = m-1;
                } else
                    f = m+1;
            }
            
            int ans2 = ans;
            f = 0; l = ans-1;
            while(f <= l) {
                int m = (f+l)/2;
                li s = b[m] - b[ans];
                li ts = x*(ans-m);
                li req = ts - s;
                if(m >= req) {
                    ans2 = m;
                    l = m-1;
                } else
                    f = m+1;
            }

            cout<<(n-ans2)<<"\n";
        }
    }
    return 0;
}