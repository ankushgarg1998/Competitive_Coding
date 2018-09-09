#include <iostream>
#include <algorithm>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>=b; i--)
using namespace std;
int main() {
    test {
        int n, k, m, x;
        cin>>n>>k>>m;
        int a[n];
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n) {
            cin>>x;
            a[i] -= x;
        }
        int c[k+m];
        loop(i, 0, k+m)
            cin>>c[i];
        
        sort(a, a+n, greater<int>());
        sort(c, c+(k+m), greater<int>());

        // loop(i, 0, n)
        //     cout<<a[i]<<" ";
        // cout<<"\n";

        for(int i=0, j=0; i<n && j<(k+m); i++) {
            while(c[j] > a[i])
                ++j;
            a[i] -= c[j];
            ++j;
        }

        lli ans = 0;
        loop(i, 0, n)
            ans += a[i];
        cout<<ans<<"\n";
    }
    return 0;
}