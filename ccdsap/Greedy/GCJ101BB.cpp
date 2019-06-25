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
    int tes;
    cin>>tes;
    loop(te, 1, tes+1) {
        cout<<"Case #"<<te<<": ";
        lli n, k, b, t;
        cin>>n>>k>>b>>t;
        long double x[n], v[n], a[n];
        loop(i, 0, n)
            cin>>x[i];
        loop(i, 0, n) {
            cin>>v[i];
            a[i] = (b-x[i])/v[i];
        }
        lli blocks=0, chicks=0, ansb=0;
        loopr(i, n-1, 0) {
            if(a[i] <= t) {
                ++chicks;
                ansb += blocks;
                if(chicks >= k)
                    break;
            } else
                ++blocks;
        }
        if(chicks >= k)
            cout<<ansb<<"\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
    return 0;
}