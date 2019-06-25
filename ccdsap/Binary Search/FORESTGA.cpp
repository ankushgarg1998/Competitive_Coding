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

int n;
lli w, l, ans=0;

bool month(lli x, lli *h, lli *r) {
    lli aw = 0;
    loop(i, 0, n) {
        aw += ((h[i]+(x*r[i])) >= l ? (h[i]+(x*r[i])): 0);
        if(aw >= w)
            return true;
    }
    return false;
}

int main() {
    cin>>n>>w>>l;
    lli h[n], r[n];
    loop(i, 0, n)
        cin>>h[i]>>r[i];
    lli first=0, last=w;
    while(first<=last) {
        lli mid = (first+last)/2;
        if(month(mid, h, r)) {
            ans = mid;
            last = mid-1;
        } else
            first = mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}