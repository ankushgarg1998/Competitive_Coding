// base 0 
#include<bits/stdc++.h>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

lli dp[40][40][40][2];

lli rec(int ai, int bi, int *c, int i, int carry) {
    if(ai < 0 || bi < 0)
        return 0;
    if(c[i] == -1) {
        if(carry)
            return 0;
        if(ai==0 && bi==0)
            return 1;
        return 0;
    }
    int x = dp[ai][bi][i][carry];
    if(x != -1)
        return x;
    if(c[i] == 0) {
        if(carry) {
            return dp[ai][bi][i][carry] = (rec(ai-1, bi, c, i+1, 1) + rec(ai, bi-1, c, i+1, 1));
        } else {
            return dp[ai][bi][i][carry] = (rec(ai, bi, c, i+1, 0) + rec(ai-1, bi-1, c, i+1, 1));
        }
    } else {
        if(carry) {
            return dp[ai][bi][i][carry] = (rec(ai, bi, c, i+1, 0) + rec(ai-1, bi-1, c, i+1, 1));
        } else {
            return dp[ai][bi][i][carry] = (rec(ai-1, bi, c, i+1, 0) + rec(ai, bi-1, c, i+1, 0));
        }
    }
}

int main() {
    test {
        init(dp, -1);
        lli a, b, c, a1, b1, c1;
        cin>>a>>b>>c;
        a1 = a;
        b1 = b;
        c1 = c;
        int ai = 0, bi = 0, ci = 0, i;
        int ar[40] = {0}, br[40] = {0}, cr[40] = {0};

        i=0;
        while(c) {
            if(c & 1) {
                ++ci;
                cr[i] = 1;
            }
            c >>= 1;
            ++i;
        }
        cr[i] = -1;

        i=0;
        while(a) {
            if(a & 1) {
                ++ai;
                ar[i] = 1;
            }
            a >>= 1;
            ++i;
        }
        ar[i] = -1;

        i=0;
        while(b) {
            if(b & 1) {
                ++bi;
                br[i] = 1;
            }
            b >>= 1;
            ++i;
        }
        br[i] = -1;

        // cout<<ci<<"\n";
        // loopr(i, 30, 0)
        //     cout<<cr[i]<<" ";
        // cout<<"\n";
        cout<<rec(ai, bi, cr, 0, 0)<<"\n";
    }
    return 0;
}