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

li NANO2 = 500000000;
li NANO4 = 250000000;

int main() {
    int test; cin>>test;
    li A, B;
    cin>>A>>B;
    for(int t=1; t<=test; t++) {
        string s;
        int tries = 300;
        bool fin = false, stop = false;
        li px = 0, py = 0;

        loop(i, -3, 4) {
            loop(j, -3, 4) {
                cout<<i*NANO4<<" "<<j*NANO4<<"\n";
                --tries;
                cin>>s;
                if(s == "CENTER") {
                    fin = true;
                    stop = true;
                    break;
                } else if(s == "HIT") {
                    px = i*NANO4;
                    py = j*NANO4;
                    stop = true;
                }
            }
            if(stop == true)
                break;
        }

        li leftmostx = px, rightmostx = px, ansx = px;
        if(!fin) {
            li l = MANO, r = px;
            while(l <= r) {
                li mid = (l+r)/2;
                cout<<mid<<" "<<py<<"\n";
                --tries;
                cin>>s;
                if(s == "CENTER" || tries == 0) {
                    fin = true;
                    break;
                } else if(s == "MISS") {
                    l = mid + 1;
                } else {
                    leftmostx = mid;
                    r = mid - 1;
                }
            }
        }

        if(!fin) {
            li l = px, r = NANO;
            while(l <= r) {
                li mid = (l+r)/2;
                cout<<mid<<" "<<py<<"\n";
                --tries;
                cin>>s;
                if(s == "CENTER" || tries == 0) {
                    fin = true;
                    break;
                } else if(s == "MISS") {
                    r = mid - 1;
                } else {
                    rightmostx = mid;
                    l = mid + 1;
                }
            }
            ansx = (leftmostx + rightmostx)/2;
        }

        li topmosty = py, bottommosty = py, ansy = py;
        if(!fin) {
            li l = MANO, r = py;
            while(l <= r) {
                li mid = (l+r)/2;
                cout<<ansx<<" "<<mid<<"\n";
                --tries;
                cin>>s;
                if(s == "CENTER" || tries == 0) {
                    fin = true;
                    break;
                } else if(s == "MISS") {
                    l = mid + 1;
                } else {
                    bottommosty = mid;
                    r = mid - 1;
                }
            }
        }

        if(!fin) {
            li l = py, r = NANO;
            while(l <= r) {
                li mid = (l+r)/2;
                cout<<ansx<<" "<<mid<<"\n";
                --tries;
                cin>>s;
                if(s == "CENTER" || tries == 0) {
                    fin = true;
                    break;
                } else if(s == "MISS") {
                    r = mid - 1;
                } else {
                    topmosty = mid;
                    l = mid + 1;
                }
            }
            ansy = (bottommosty + topmosty)/2;
        }

        if(!fin) {
            cout<<ansx<<" "<<ansy<<"\n";
            --tries;
            cin>>s;
            if(s != "CENTER" && tries != 0) {
                while(tries--) {
                    cout<<"0 0\n";
                }
            }
        }
    }
    return 0;
}