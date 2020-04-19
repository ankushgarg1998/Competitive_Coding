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

int main() {
    string s = "asdf*asdf*asdf";
    cout<<s.find_first_of("*")<<"\n";
    cout<<s.find_last_of("*")<<"\n";
    string k = s.substr(0, 0);
    cout<<k<<"\n";
    cout<<s.find_last_of("afd")<<"\n";
    if(s.find_last_of("afd")) {
        cout<<"perfect";
    }
    return 0;
}