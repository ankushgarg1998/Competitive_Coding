#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int n;
int a[1010];

int find_cost(int x) {
    int ans = 0;
    loop(i, 0, n) {
        if(a[i] != x)
            ans += (abs(a[i] - x) - 1);
    }
    return ans;
}

int main() {
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    
    int mincost = INT_MAX;
    int t=1;
    loop(i, 1, 101) {
        int cost = find_cost(i);
        if(cost < mincost) {
            mincost = cost;
            t = i;
        }
    }
    cout<<t<<" "<<mincost<<"\n";
    return 0;
}