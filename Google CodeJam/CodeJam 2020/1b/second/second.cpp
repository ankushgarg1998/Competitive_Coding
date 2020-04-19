#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
lli power(lli a, lli p) { lli ans=1; while(p>0) { if(p&1) ans*=a; p>>=1; a*=a; } return ans; }
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

li MANO = -1000000000;
li NANO = 1000000000;

int main() {
    int test; cin>>test;
    li A, B;
    cin>>A>>B;
    for(int t=1; t<=test; t++) {
        string s;
        bool fin = false;
        loop(i, -5, +6) {
            loop(j, -5, +6) {
                cout<<i<<" "<<j<<"\n";
                cin>>s;
                if(s == "WRONG" || s == "CENTER") {
                    fin = true;
                    break;
                }
            }
            if(fin)
            break;
        }
    }
    return 0;
}