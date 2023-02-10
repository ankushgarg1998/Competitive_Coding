#include<iostream>
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

string rev(string s) {
    string ans = "";
    loopr(i, s.size()-1, 0) {
        ans += s[i];
    }
    return ans;
}

string comp(string s) {
    string ans = "";
    loop(i, 0, s.size()) {
        if(s[i] == '0')
            ans += '1';
        else
            ans += '0';
    }
    return ans;
}

int main() {
    int t, b;
    cin>>t>>b;
    if (b == 10) {
        while (t--) {
            string ans = "", s;
            loop(i, 1, b+1) {
                cout<<i<<"\n";
                cin>>s;
                ans += s;
            }
            cout<<ans<<"\n";
            cin>>s;
            if(s != "Y")
                break;
        }
    } else if (b == 20) {
        while (t--) {
            string ans="", s, x1="", x2="", x3="", x4="", y1="", y2="";
            loop(i, 1, 6) {
                cout<<i<<"\n";
                cin>>s;
                x1 += s;
            }
            loop(i, 16, 21) {
                cout<<i<<"\n";
                cin>>s;
                x4 += s;
            }
            loop(i, 6, 11) {
                cout<<i<<"\n";
                cin>>s;
                x2 += s;
            }
            loop(i, 11, 16) {
                cout<<i<<"\n";
                cin>>s;
                x3 += s;
            }

            loop(i, 1, 6) {
                cout<<i<<"\n";
                cin>>s;
                y1 += s;
            }
            loop(i, 6, 11) {
                cout<<i<<"\n";
                cin>>s;
                y2 += s;
            }

            ans += y1;
            ans += y2;

            if(y2 == x2) {
                ans += x3;
            } else if(y2 == comp(x2)) {
                ans += comp(x3);
            } else if(y2 == rev(x3)) {
                ans += rev(x2);
            } else {
                ans += comp(rev(x2));
            }

            if(y1 == x1) {
                ans += x4;
            } else if(y1 == comp(x1)) {
                ans += comp(x4);
            } else if(y1 == rev(x4)) {
                ans += rev(x1);
            } else {
                ans += comp(rev(x1));
            }

            cout<<ans<<"\n";
            cin>>s;
            if(s != "Y")
                break;
        }
    }
    return 0;
}
// change header