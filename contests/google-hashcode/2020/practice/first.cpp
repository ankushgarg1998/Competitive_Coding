#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define li long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

pair<li, string> best(vector<li> &arr, string s, li m, int i) {
    if(i == (int)arr.size())
        return make_pair(0, s);
    auto val1 = best(arr, s, m, i+1);
    auto ans = make_pair(val1.first, val1.second);
    if(m >= arr[i]) {
        auto val2 = best(arr, s, m-arr[i], i+1);
        li x1 = val1.first, x2 = arr[i] + val2.first;
        if(x2 > x1) {
            string ss = val2.second;
            ss[i] = '1';
            ans = make_pair(x2, ss);
        }
    }
    return ans;
}

int main() {
    li m, n;
    cin>>m>>n;
    vector<li> arr(n);
    vector<int> v;
    string s = "";
    loop(i, 0, n) {
        cin>>arr[i];
        s += '0';
    }
    auto ans = best(arr, s, m, 0);
    loop(i, 0, (int)ans.second.size()) {
        if(ans.second[i] == '1') {
            v.push_back(i);
        }
    }
    cout<<v.size()<<"\n";
    for(li x: v)
        cout<<x<<" ";
    return 0;
}