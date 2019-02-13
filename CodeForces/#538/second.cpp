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
    int n, k, m;
    cin>>n>>m>>k;
    vector<pair<lli, int> > a;
    lli x;
    loop(i, 0, n) {
        cin>>x;
        a.push_back(make_pair(x, i+1));
    }
    sort(a.begin(), a.end());
    vector<int> v;
    lli sum = 0;
    loop(i, n-(m*k), n) {
        // cout<<a[i].first<<" ";
        v.push_back(a[i].second);
        sum += a[i].first;
    }
    sort(v.begin(), v.end());
    int i=m-1;
    cout<<sum<<"\n";
    while(i<v.size()-1) {
        cout<<v[i]<<" ";
        i += m;
    }
    return 0;
}