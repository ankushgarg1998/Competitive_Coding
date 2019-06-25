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

lli it = 0;

lli vasya(lli n, lli k)
    {
    lli vas=0, pet=0;
    while(n>=10)
        {
        if(n > k)
            {
            vas += k;
            n -= k;
            }
        else
            {
            vas += n;
            return vas;
            }
        ++it;
        pet += (lli)n/10;
        n -= (lli)n/10;
        }
    return vas+n;
    }

int main()
    {
    lli n, k, x, half, i=1, l=1, r, mid, ans;
    cin>>n;
    r = n;
    ans = n;
    half = n/2;
    if(n%2 != 0)
        ++half;
    while(l<=r)
        {
        mid = (l+r)/2;
        x = vasya(n, mid);
        // cout<<"x = "<<mid<<"\n";
        if(x >= half)
            {
            ans = mid;
            r = mid-1;
            }
        else
            l = mid+1;
        }
    cout<<ans<<"\n";
    return 0;
    }