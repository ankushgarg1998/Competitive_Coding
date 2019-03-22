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
    string s;
    cin>>s;
    lli ans = 0;
    loop(i, 0, s.size()) {
        if((s[i]-'0')%2 == 0) {
            ans += (i+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}