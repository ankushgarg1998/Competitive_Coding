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
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

vector<int> graph[100010];
bool visited[100010] = {0};
int p=0;

void dfs(int x) {
    if(!visited[x]) {
        ++p;
        visited[x] = 1;
        for(auto v: graph[x])
            dfs(v);
    }
}

int main() {
    int n, k, a, b, c;
    cin>>n>>k;
    loop(i, 0, n-1) {
        cin>>a>>b>>c;
        if(c == 0) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    lli ans = power(n, k, MOD);
    loop(i, 1, n+1) {
        if(!visited[i]) {
            p = 0;
            dfs(i);
            // cout<<p<<" ";
            ans -= power(p, k, MOD);
            ans += MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}