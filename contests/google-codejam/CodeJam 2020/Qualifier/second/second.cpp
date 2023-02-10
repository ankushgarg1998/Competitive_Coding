#include<iostream>
#include<vector>
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

string concatBrackets(string ans, int v) {
    if(v == 0)
        return ans;
    string ch;
    if(v < 0) {
        v *= -1;
        ch = ")"; 
    } else
        ch = "(";
    loop(i, 0, v)
        ans += ch;
    return ans;
}

int main() {
    testing {
        string s;
        cin>>s;
        int opened = s[0]-'0';
        string ans = concatBrackets("", opened);
        ans += s[0];
        loop(i, 1, s.size()) {
            int val = (s[i] - '0') - opened;
            ans = concatBrackets(ans, val);
            ans += s[i];
            opened += val;
        }
        ans = concatBrackets(ans, -1*opened);
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}