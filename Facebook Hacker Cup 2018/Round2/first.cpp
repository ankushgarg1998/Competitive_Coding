#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define tes int t; cin>>t; for(int test=1; test<=t; test++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

int main()
    {
    tes {
        int n, k;
        cin>>n>>k;
        if (n == 2 || k <= 2 ) {
            cout<<"Case #"<<test<<": 0\n1\n1 "<<n<<" 1"<<"\n";
        } else {
            int ans = (k*(k-1))/2;
            ans -= k;
            if(n < k) {
                int l = k-n;
                ans -= ((l*(l+1))/2);
            }
            cout<<"Case #"<<test<<": "<<ans<<"\n";
            cout<<min(n, k)<<"\n";
            cout<<"1 "<<n<<" "<<k<<"\n";
            if (n < k) {
                loop(i, 1, n) {
                    cout<<i<<" "<<i+1<<" "<<k-i<<"\n";
                }
            } else {
                loop(i, 1, k-1) {
                    cout<<i<<" "<<i+1<<" "<<k-i<<"\n";
                }
                cout<<k-1<<" "<<n<<" 1\n";
            }
        }
    }
    return 0;
    }