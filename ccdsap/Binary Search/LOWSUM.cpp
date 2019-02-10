#include <bits/stdc++.h>
#define lli long long
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int k, q;
        cin>>k>>q;
        lli a[k], b[k];
        loop(i, 0, k)
            cin>>a[i];
        loop(i, 0, k)
            cin>>b[i];
        sort(a, a+k);
        sort(b, b+k);

        lli c[1000000];
        int r=0;
        loop(i, 0, min(k, 1000)) {
            loop(j, 0, min(k, 1000)) {
                c[r] = (a[i] + b[j]);
                ++r;
            }
        }

        sort(c, c+r);

        while(q--) {
            int qi;
            cin>>qi;
            cout<<c[qi-1]<<"\n";
        }
    }
    return 0;
}