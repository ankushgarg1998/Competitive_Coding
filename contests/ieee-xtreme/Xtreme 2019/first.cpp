#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int n;
long long x, b, fincost=0;

void func(vector<vector<long long> > &cost, int i, long long c) {
    if(i == n) {
        if(c<=b)
            fincost = max(fincost, c);
        return;
    }
    
    loop(j, 0, (int)cost[i].size()) {
        func(cost, i+1, c+cost[i][j]);
    }
}

long long func2(vector<vector<long long> > &cost, int i, long long b) {
    long long ans = 0;
    loop(j, 0, (int)cost[i].size()) {
        long long w = cost[i][j];
        if(b>=w) {
            ans = max(ans, w + func2(cost, i+1, b-w));
        }
    }
    return dp[i][b] = ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        fincost = 0;
        cin>>b;
        cin>>n;
        int sizes[n];
        vector<vector<long long> > cost(n, vector<long long>() );
        loop(i, 0, n)
            cin>>sizes[i];
        loop(i, 0, n) {
            loop(j, 0, sizes[i]) {
                cin>>x;
                cost[i].push_back(x);
            }
        }
        
        func(cost, 0, 0);
        cout<<fincost<<"\n";
    }
    return 0;
}