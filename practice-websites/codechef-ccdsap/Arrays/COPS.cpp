#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

int main() {
    int m, x, y;
    test {
        cin>>m>>x>>y;
        int d = x*y, arr[101]={0}, p;
        loop(i, 0, m) {
            cin>>p;
            ++arr[max(1, p-d)];
            --arr[min(100, p+d)];
        }
        int ct = 0, t = 0;
        loop(i, 1, 101) {
            if(arr[i] > 0)
                t += arr[i];
            else if(t == 0) {
                // cout<<i<<" ";
                ++ct;
            }
            if(arr[i] < 0)
                t += arr[i];
        }
        cout<<ct<<"\n";
    }
    return 0;
}