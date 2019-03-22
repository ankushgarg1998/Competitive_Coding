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
    int n;
    cin>>n;
    lli a[n];
    loop(i, 0, n)
        cin>>a[i];
    lli cur = LLONG_MAX, ans = 0;
    loopr(i, n-1, 0) {
        cur = min(cur-1, a[i]);
        if(cur <= 0) break;
        ans += cur;
    }
    cout<<ans<<"\n";
    return 0;
}