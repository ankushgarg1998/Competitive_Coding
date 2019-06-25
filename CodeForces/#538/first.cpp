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
    int x, y, z, a, b, c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    if(a<x)
        cout<<"NO";
    else if(b + (a-x) < y)
        cout<<"NO";
    else if(a+b+c -(x+y) < z)
        cout<<"NO";
    else
        cout<<"YES";
    cout<<"\n";
    return 0;
}