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
    int n, a[210], count=0;
    cin>>n;
    loop(i, 0, 2*n)
        cin>>a[i];
    loops(i, 0, 2*n, 2) {
        int j = i+1;
        for(; a[j]!=a[i]; ++j);
        for(;j != i+1; --j) {
            swap(a[j], a[j-1]);
            ++count;
        }
    }
    cout<<count<<"\n";
    return 0;
}