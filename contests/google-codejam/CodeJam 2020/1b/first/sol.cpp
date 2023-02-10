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

bool even(li x) {
    return (x&1) == 0;
}

bool odd(li x) {
    return (x&1) != 0;
}

bool works(li x, li y) {
    if(x==0 && y==0)
        return true;
    x /= 2;
    y /= 2;
    return !((even(x) && even(y)) || (odd(x) && odd(y)));
}

int main() {
    testing {
        li x, y;
        cin>>x>>y;
        string ans = "";
        bool oppH = false, oppV = false;
        if(x < 0) {
            x *= -1;
            oppH = true;
        }
        if(y < 0) {
            y *= -1;
            oppV = true;
        }
        if(!((odd(x) && odd(y)) || (even(x) && even(y)))) {
            while(x!=0 || y!=0) {
                // cout<<x<<" "<<y<<"\n";
                if(odd(x)) {
                    if(works(x-1, y)) {
                        x -= 1;
                        ans += (oppH? "W": "E");
                    } else {
                        x += 1;
                        ans += (oppH? "E": "W");
                    }
                } else {
                    if(works(x, y-1)) {
                        y -= 1;
                        ans += (oppV? "S": "N");
                    } else {
                        y += 1;
                        ans += (oppV? "N": "S");
                    }
                }
                x /= 2;
                y /= 2;
            }
        }
        cout<<"Case #"<<t<<": "<<(ans == ""? "IMPOSSIBLE": ans)<<"\n";   
    }
    return 0;
}