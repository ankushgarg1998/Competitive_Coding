#include<bits/stdc++.h>
#define lli long long int
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    int val = 0;
    lli n, l, r, prev = 0;
    map<lli, int> v;
    map<int, lli> ans;
    cin>>n;
    vector<lli> c(n+10, 0);
    loop(i, 0, n) {
        cin>>l>>r;
        ++v[l];
        --v[r+1];
    }

    for(auto x: v) {
        ans[val] += (x.first - prev);
        prev = x.first;
        val += x.second;
    }

    loop(i, 1, n+1) {
        cout<<ans[i]<<" ";
    }
    return 0;
}