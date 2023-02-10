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
    test {
        li l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        cout<<l1<<" "<<(r2 == l1? l2: r2)<<"\n";
    }
    return 0;
}