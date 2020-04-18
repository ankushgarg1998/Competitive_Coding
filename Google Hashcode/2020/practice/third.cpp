#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define li long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    li m, n, sum = 0;
    cin>>m>>n;
    vector<li> arr(n);
    stack<int> v;
    loop(i, 0, n)
        cin>>arr[i];

    loopr(i, n-1, 0) {
        if(arr[i] <= m) {
            v.push(i);
            m -= arr[i];
        }
    }
    cout<<v.size()<<"\n";
    while(!v.empty()) {
        cout<<v.top()<<" ";
        v.pop();
    }
    return 0;
}