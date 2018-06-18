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
    lli l, r, x, y, lcm, gcd, sq, em, count = 0;
    cin>>l>>r>>x>>y;
    lcm = max(x, y);
    gcd = min(x, y);
    sq = sqrt(lcm);
    // cout<<sq;
    em = lcm*gcd;

    for(lli i=1; i<=sq; i++)
        {
        if(lcm%i == 0)
            {
            if(i>=l && i<=r)
                {
                lli j = em/i;
                if(lcm%j == 0 && j>=l && j<=r)
                    {
                    lli g = __gcd(i, j);
                    if(g == gcd)
                        {
                        ++count;
                        // cout<<i<<' '<<j<<"\n";
                        }
                    }
                }
            
            lli ni = lcm/i;
            if(i != ni && ni>=l && ni<=r)
                {
                lli j = em/ni;
                if(lcm%j == 0 && j>=l && j<=r)
                    {
                    lli g = __gcd(ni, j);
                    if(g == gcd)
                        {
                        ++count;
                        // cout<<ni<<' '<<j<<"\n";
                        }
                    }
                }
            }
        }

    cout<<count<<"\n";
    return 0;
    }