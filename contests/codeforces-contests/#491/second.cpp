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

int r(double x)
    {
    return x+0.5;
    }

int main()
    {
    int n, a[110], sum=0;
    cin>>n;
    loop(i, 0, n)
        {
        cin>>a[i];
        sum += a[i];
        }
    sort(a, a+n);

    double avg = sum / (double)n;
    int i=0;
    // cout<<r(avg);

    while(r(avg) < 5)
        {
        sum += (5 - a[i]);
        avg = sum / (double)n;
        ++i;
        }
    cout<<i<<"\n";
    return 0;
    }