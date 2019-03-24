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

li county(const set<pair<li, li> > &s) {
    li last = 0, ans = 0;
    for(auto p: s) {
        if(p.second >= last) {
            ++ans;
            last = p.first;
        }
    }
    return ans;
}

int main() {
    test {
        li n, k, a, b, c;
        cin>>n>>k;
        unordered_map<li, set<pair<li, li> > > r;
        loop(i, 0, n) {
            cin>>a>>b>>c;
            r[c].insert(make_pair(b, a));
        }
        li ans = 0;
        for(auto x: r) {
            ans += county(x.second);
        }
        cout<<ans<<"\n";
    }
    return 0;
}