#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long long
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    test {
        int n;
        cin>>n;
        li b, l;
        unordered_map<li, multiset<li> > m;
        multiset<li> s;
        vector<li> others;
        loop(i, 0, n) {
            cin>>b>>l;
            m[b].insert(l);
        }
        li nb = 0, ans = 0, sec=0;
        for(auto p: m) {
            multiset<li>::iterator it = (p.second).begin();
            // ans += ((*it) * (++nb));
            s.insert(*it);
            ++it;
            for(; it != (p.second).end(); ++it)
                sec += (*it);
        }
        for(auto x: s)
            ans += ((++nb)*x);
        ans += (nb*sec);
        cout<<ans<<"\n";
    }
    return 0;
}