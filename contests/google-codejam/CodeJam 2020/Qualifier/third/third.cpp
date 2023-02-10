#include<iostream>
#include<vector>
#include<algorithm>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
lli power(lli a, lli p) { lli ans=1; while(p>0) { if(p&1) ans*=a; p>>=1; a*=a; } return ans; }
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

bool sortbysec(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b) { 
    if(a.second.first == b.second.first)
        return (a.second.second < b.second.second);
    return (a.second.first < b.second.first); 
} 

int main() {
    testing {
        int n, s, e;
        cin>>n;
        pair<int, pair<int, int> > activities[n];
        char ans[n+1];
        ans[n] = 0;
        loop(i, 0, n) {
            cin>>s>>e;
            activities[i] = make_pair(i, make_pair(s, e));
        }
        sort(activities, activities+n, sortbysec);
        
        int ce = 0, je = 0;
        bool impossible = false;
        loop(i, 0, n) {
            if (ce <= activities[i].second.first) {
                ans[activities[i].first] = 'C';
                ce = activities[i].second.second;
            } else if (je <= activities[i].second.first) {
                ans[activities[i].first] = 'J';
                je = activities[i].second.second;
            } else {
                impossible = true;
                break;
            }
        }
        if(impossible) {
            cout<<"Case #"<<t<<": IMPOSSIBLE\n";
        } else {
            cout<<"Case #"<<t<<": "<<ans<<"\n";
        }
    }
    return 0;
}