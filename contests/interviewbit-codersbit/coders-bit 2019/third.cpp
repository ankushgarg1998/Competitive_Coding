#include<bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
vector<vector<long long> > dp(100010, vector<long long>(2, -1));

long long func(vector<int> &A, int index, int odd) {
    if(index == A.size())
        return 0;
    if(dp[index][odd] != -1)
        return dp[index][odd];
    long long ans = 0;
    if(A[index]%2 == 0) { // A[i] is even
        if(odd) {
            ans = 1 + (2*func(A, index+1, 1));
        } else {
            ans = 2*func(A, index+1, 0);
        }
    } else { // A[i] is odd
        if(odd) {
            ans = func(A, index+1, 1);
            ans %= MOD;
            ans += func(A, index+1, 0);
        } else {
            ans = 1 + func(A, index+1, 1);
            ans %= MOD;
            ans += func(A, index+1, 0);
        }
    }
    ans %= MOD;
    dp[index][odd] = ans;
    return ans;
}

int main() {
    vector<int> A = { -78, 90, -91, -4, -66, -82, 19, -53, 8, -9 };

    if(A.size() == 0)
        return 0;
    if(A.size() == 1)
        return (A[0]%2 == 0? 0: 1);
        
    long long ans = (A[0]%2 == 0? 0: 1);
    if(ans == 0) { // A[0] is even
        ans += (2*func(A, 1, 0));
    } else {
        ans += func(A, 1, 0);
        ans %= MOD;
        ans += func(A, 1, 1);
    }
    ans %= MOD;
    cout<<(int)ans;
}
