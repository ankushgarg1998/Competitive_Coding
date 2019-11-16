#include<bits/stdc++.h>
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

int main() {
    testing {
        string s, s1="";
        cin>>s;
        for(int i=0 ; i<s.size(); i++) {
            if(s[i] == '4') {
                s[i] = '2';
                s1 += "2";
            } else
                s1 += "0";
        }
        cout<<"Case #"<<t<<": "<<s<<" "<<s1<<"\n";
    }
    return 0;
}