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

void finish(int y, int x, li left) {
    if(x == y) {
        while(left--)
            cout<<++y<<" "<<++x<<"\n";
    } else if(x == 1) {
        while(left--)
            cout<<++y<<" 1\n";
    }
}

int main() {
    testing {
        li n;
        cin>>n;
        cout<<"Case #"<<t<<": \n";
        cout<<"1 1\n";
        if(n < 100) {
            finish(1, 1, n-1);
        } else {
            int extras = 0;
            int x=1, y=1;
            string s = bitset<30>(n-30).to_string();
            reverse(s.begin(), s.end());
            if(s[0] == '0')
                ++extras;
            cout<<s<<"\n";
            loop(i, 1, 30) {
                if(s[i] == '0') {
                    ++extras;
                    if(x == 1)
                        cout<<++y<<" 1\n";
                    else
                        cout<<++y<<" "<<++x<<"\n";
                } else {
                    ++y;
                    if(x == 1) {
                        loop(k, 1, y+1)
                            cout<<y<<" "<<k<<"\n";
                        x = y;
                    } else {
                        loopr(k, y, 1)
                            cout<<y<<" "<<k<<"\n";
                        x = 1;
                    }
                }
            }
            finish(y, x, 30-extras);
        }
    }
    return 0;
}