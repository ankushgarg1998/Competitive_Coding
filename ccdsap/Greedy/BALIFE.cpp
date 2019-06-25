#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long long
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() { 
    while(1) {
        li n;
        cin>>n;
        if(n == -1)
            break;
        li a[n], tot=0, b[n];
        loop(i, 0, n) {
            cin>>a[i];
            tot += a[i];
            b[i] = tot;
        }
        if(tot%n != 0) {
            cout<<"-1\n";
            continue;
        }
        li each = tot/n, ans=0;
        loop(i, 0, n) {
            if(a[i] > each) {
                li right = b[i] - ((i+1)*each);
                li left = (i*each) - (i==0? 0:b[i-1]);
                ans = max(ans, max(left, right));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}