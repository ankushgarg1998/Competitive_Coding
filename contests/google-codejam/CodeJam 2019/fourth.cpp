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

vector<bool> ans(1111, false);

string times(string ch, int f, int l) {
    string str = "";
    loop(i, f, l)
        str += ch;
    return str;
}

void func(vector<string> &vc, int f, int l, int level) {
    if(l-f < 2) {
        vc[level] += "0";
        return;
    }
    vc[level] += times("0", f, (f+l)/2);
    vc[level] += times("1", (f+l)/2, l);
    func(vc, f, (f+l)/2, level+1);
    func(vc, (f+l)/2, l, level+1);
}

void solve(vector<string> &vc, vector<string> &va, int f, int l, int a, int b, int level, int missing) {
    // solve 2 and 1
    if(l-f < 2) {
        if(missing > 0)
            ans[f] = true;
        return;
    }
    int i=a, zero=0, one=0, q=a;
    while(i<b) {
        if(va[level][i] == '0') {
            ++zero;
            q = i+1;
        }
        else
            ++one;
        ++i;
    }
    int mid = (f+l)/2;
    int actual_zero = mid-f, actual_one = l-mid;
    solve(vc, va, f, mid, a, q, level+1, actual_zero-zero);
    solve(vc, va, mid, l, q, b, level+1, actual_one-one);
}

int main() {
    testing {
        int n, b, f;
        cin>>n>>b>>f;
        loop(i, 0, n)
            ans[i] = false;

        string s;
        vector<string> vc, va;
        loop(i, 0, 15)
            vc.push_back("");
        func(vc, 0, n, 0);

        int i=0;
        while(vc[i+1] != "") {
            cout<<vc[i]<<"\n";
            cin>>s;
            if(s == "-1")
                exit(0);
            va.push_back(s);
            ++i;
        }

        solve(vc, va, 0, n, 0, n-b, 0, b);
        loop(i, 0, n) {
            if(ans[i])
                cout<<i<<" ";
        }
        cout<<"\n";
        int g;
        cin>>g;
        if(g == -1)
            exit(0);
    }
    return 0;
}