#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n], num[10010] = {0};
    loop(i, 0, n) {
        cin>>a[i];
        ++num[a[i]];
    }
    int hcf=1;
    loopr(i, 10000, 0) {
        if(num[i] == 2) {
            hcf = i;
            break;
        }
    }

    sort(a, a+n);
    int p = a[n-1], q;
    loopr(i, n-2, 0) {
        q = a[i];
        if(__gcd(p, q) == hcf) {
            cout<<p<<" "<<q<<"\n";
            break;
        }
    }
    return 0;
}