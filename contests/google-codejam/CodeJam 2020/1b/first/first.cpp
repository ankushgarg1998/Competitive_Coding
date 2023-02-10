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

int till=30;
li X, Y;

string generator(string str, li x, li y) {
    // cout<<str<<"\n";
    // cout<<x<<" "<<y<<"\n";
    if(x==X && y==Y)
        return str;
    if(str.size() == till)
        return "IMPOSSIBLE";
    li step = pow(2, str.size());
    loop(i, 0, 4) {
        string returned_str;
        if(i == 0)
            returned_str = generator(str + "N", x, y + step);
        if(i == 1)
            returned_str = generator(str + "E", x + step, y);
        if(i == 2)
            returned_str = generator(str + "S", x, y - step);
        if(i == 3)
            returned_str = generator(str + "W", x - step, y);
            
        if(returned_str != "IMPOSSIBLE")
            return returned_str;
    }
    return "IMPOSSIBLE";
}

int main() {
    testing {
        li x, y;
        cin>>x>>y;
        X = x; Y = y;
        string ans = "IMPOSSIBLE";
        loop(i, 0, 20) {
            till = i;
            ans = generator("", 0, 0);
            if(ans != "IMPOSSIBLE")
                break;
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";   
    }
    return 0;
}