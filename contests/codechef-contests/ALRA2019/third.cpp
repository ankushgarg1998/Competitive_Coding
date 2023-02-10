#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dp[30];

int findmin(vector<int> &v, int x) {
    // if(dp[x] != -1)
    //     return dp[x];
    if(v[x] == -1)
        return x;
    else
        return min(x, findmin(v, v[x]));
}

int main() {
    test {
        loop(i, 0, 30)
            dp[i] = -1;
        int n, m;
        string s;
        cin>>n>>m;
        cin>>s;
        vector<int> alpha(30);
        loop(i, 0, 30)
            alpha[i] = -1;
        while(m--) {
            string temp1, temp2;
            cin>>temp1>>temp2;
            int ch1 = temp1[0] - 'a', ch2 = temp2[0] - 'a';
            alpha[ch1] = ch2;
        }

        loop(i, 0, 30) {
            if(alpha[i] != -1) {
                alpha[i] = findmin(alpha, alpha[i]);
            }
        }

        loop(i, 0, s.size()) {
            int val = s[i] - 'a';
            if(val > alpha[val])
                s[i] = (alpha[val] + 'a');
        }

        cout<<s<<"\n";
    }
    return 0;
}