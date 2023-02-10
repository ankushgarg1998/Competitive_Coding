#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    li a[n], l[m], r[m];
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, m) {
        cin>>l[i]>>r[i];
        --l[i]; --r[i];
    }

    li maxmax=0, fi, fj, total=0;
    li ansans=INT_MIN, notnot;
    loop(i, 0, n-1) {
        loop(j, i+1, n) {
            li lowi=0, lowj=0;
            // li arri[m], arrj[m];
            loop(k, 0, m) {
                if(i>=l[k] && i<=r[k]) {
                    if(j>=l[k] && j<=r[k]) {
                        
                    } else {
                        // arri[lowi] = k;
                        ++lowi;
                    }
                } else {
                    if(j>=l[k] && j<=r[k]) {
                        // arrj[lowj] = k;
                        ++lowj;
                    }
                }
            }

            li maxi = abs(a[i] - a[j]), tot=0;
            li ans = INT_MIN, notans;
            if(abs((a[i]-lowi) - a[j]) > maxi) {
                maxi = abs((a[i]-lowi) - a[j]);
                ans = i;
                notans = j;
                tot = lowi;
            }
            if(abs(a[i] - (a[j]-lowj)) > maxi) {
                maxi = abs(a[i] - (a[j]-lowj));
                ans = j;
                notans = i;
                tot = lowj;
            }

            if(maxi > maxmax) {
                maxmax = maxi;
                fi = i; fj = j;
                ansans = ans;
                total = tot;
                notnot = notans;
            }
        }
    }

    cout<<maxmax<<"\n"<<total<<"\n";
    // cout<<ansans<<"\n";
    loop(i, 0, m) {
        if(ansans>=l[i] && ansans<=r[i]) {
            if(!(notnot>=l[i] && notnot<=r[i]))
                cout<<i+1<<" ";
        }
    }
    cout<<"\n";
    return 0;
}