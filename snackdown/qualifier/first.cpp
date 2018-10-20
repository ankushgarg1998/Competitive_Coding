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
using namespace std;

int main() {
    test {
            int n, k;
            cin>>n>>k;
            li a[n];
            loop(i, 0, n)
                cin>>a[i];
            sort(a, a+n, greater<int>());
            int last = a[k-1];
            while(a[k] == last && k<n) {
                ++k;
            }
            cout<<k<<"\n";
        }
    return 0;
}