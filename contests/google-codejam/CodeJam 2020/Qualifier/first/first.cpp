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
    testing {
        int n, k=0, r=0, c=0;
        bool repeated;
        cin>>n;
        int a[n][n];
        loop(i, 0, n) {
            repeated = false;
            vector<bool> visited(n+1, false);
            loop(j, 0, n) {
                cin>>a[i][j];
                k += (i==j? a[i][j]: 0);
                if(!repeated && visited[a[i][j]]) {
                    repeated = true;
                    ++r;
                }
                visited[a[i][j]] = true;
            }
        }
        loop(j, 0, n) {
            vector<bool> visited(n+1, false);
            loop(i, 0, n) {
                if(visited[a[i][j]]) {
                    ++c;
                    break;
                }
                visited[a[i][j]] = true;
            }
        }
        cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<"\n";
    }
    return 0;
}