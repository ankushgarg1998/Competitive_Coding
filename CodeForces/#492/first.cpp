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
    li n, count = 0, a[] = {100, 20, 10, 5, 1};
    cin>>n;
    loop(i, 0, 5) {
        if(n>=a[i]) {
            li notes = (n/a[i]);
            count += notes;
            n -= (notes*a[i]);
        }
    }
    cout<<count<<"\n";
    return 0;
    }