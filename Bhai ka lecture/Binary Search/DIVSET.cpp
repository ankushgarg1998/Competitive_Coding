#include <bits/stdc++.h>
#define lli long long int
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int n, k, c;

bool func(int x, lli *a) {
    vector<vector<lli> > v(x);
    int tv=0;
    loop(i, 0, n) {
        if(v[tv].empty()) {
            v[tv].push_back(a[i]);
            tv = (tv+1)%x;
        } else if(a[i] >= c*v[tv].back()) {
            v[tv].push_back(a[i]);
            tv = (tv+1)%x;
        }
    }
    if(v[x-1].size() >= k)
        return 1;
    else
        return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k>>c;
        lli a[n];
        loop(i, 0, n)
            cin>>a[i];
        
        sort(a, a+n);
        int start=1, end=300000, mid, ans=0;
        while(start <= end) {
            mid = (start+end)/2;
            if(func(mid, a)) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
