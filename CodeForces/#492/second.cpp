#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

int main()
    {
    lli n, mini=10000000000, ans=-1;
    cin>>n;
    vector<lli> v(n);
    loop(i, 0, n) {
        cin>>v[i];
        lli l = (v[i]/n);
        lli x = (l*n) + i + 1 + n;
        if(v[i]%n <= i)
            x -= n;
        if(x < mini) {
            ans = i+1;
            mini = x;
        }
        // cout<<x<<" ";
    }
    cout<<ans<<"\n";
    return 0;
    }