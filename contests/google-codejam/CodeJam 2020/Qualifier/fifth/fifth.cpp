#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
lli power(lli a, lli p) { lli ans=1; while(p>0) { if(p&1) ans*=a; p>>=1; a*=a; } return ans; }
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

vector<int> findUnusedNum(vector<vector<bool> > &rows, vector<vector<bool> > cols, int x, int y) {
    vector<int> unusedNums;
    loop(i, 0, rows.size()) {
        if(!rows[x][i] && !cols[y][i]) {
            unusedNums.push_back(i);
        }
    }
    return unusedNums;
}

int main() {
    int n = 5;
    vector<vector<bool> > rows(n, vector<bool>(n, 0));
    vector<vector<bool> > cols(n, vector<bool>(n, 0));

    loop(i, 0, n) {
        loop(j, 0, n) {
            vector<int> unusedNums = findUnusedNum(rows, cols, i, j);
            
        }
    }
    return 0;
}
