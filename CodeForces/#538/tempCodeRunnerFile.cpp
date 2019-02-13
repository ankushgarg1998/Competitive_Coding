#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

lli ans1(lli p, lli n) {
    lli ans = 0, pri = p;
    while(n/p > 0) {
        ans += (n/p);
        // p *= pri;
        n /= p;
    }
    return ans;
}

int main() {
    lli n, b;
    cin>>n>>b;
    bool prime[1100000];
    vector<pair<lli, lli> > pq;
    init(prime, true);
    for(lli p=2; p*p<=b; p++) {
        if(prime[p]) {
            for(lli i=p*p; i*i<=b; i+=p) {
                prime[i] = false;
            }
            lli q = 0;
            while(b%p == 0) {
                ++q;
                b /= p;
            }
            if(q != 0)
                pq.push_back(make_pair(p, q));
            if(b == 1)
                break;
        }
    }
    if(b > 1) {
        pq.push_back(make_pair(b, 1));
    }
    if(pq.size() == 1) {
        if(pq[0].second == 1)
            cout<<ans1(pq[0].first, n);
        else
            cout<<ans1(pq[0].first, n)/pq[0].second;
    } else {
        lli ans = LLONG_MAX;
        for(auto z: pq) {
            ans = min(ans, (ans1(z.first, n)/z.second));
        }
        cout<<ans;
    }
    cout<<"\n";
    return 0;
}