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
    FastIO
    test {
        li n, k, count=0;
        cin>>n>>k;
        int a[n];
        loop(i, 0, n)
            cin>>a[i];

        // making prefix array
        int pre[2010][n];
        loop(i, 0, 2010) {
            loop(j, 0, n) {
                int temp = (j == 0? 0: pre[i][j-1]);
                pre[i][j] = (a[j] <= i? temp+1: temp);
                // cout<<pre[i][j]<<" ";
            }
            // cout<<"\n";
        }

        int kth=k;
        loop(i, 0, n) {
            loop(j, i, n) {
                int len = j-i+1;
                int m = (k%len==0? k/len: (k/len)+1);
                kth = (k%m==0? k/m: (k/m)+1);
                // No. of elements smaller than kth = --kth;

                int f=0, l=2000, ans=-1, val;
                while(f<=l) {
                    int mid = (f+l)/2;
                    val = pre[mid][j] - (i==0? 0:pre[mid][i-1]);
                    if(val >= kth) {
                        ans = mid;
                        l = mid-1;
                    } else
                        f = mid+1;
                }
                f = (pre[ans][j] - (i==0? 0:pre[ans][i-1])) - (pre[ans-1][j] - (i==0? 0:pre[ans-1][i-1]));
                int t1 = pre[f][j] - (i==0? 0:pre[f][i-1]);
                int t2 = pre[f-1][j] - (i==0? 0:pre[f-1][i-1]);
                // cout<<i<<" "<<j<<"-"<<m<<" "<<kth<<":"<<ans<<" "<<f<<"\n";
                if(t1-t2 > 0) {
                    ++count;
                }
            }
        }

        cout<<count<<"\n";
    }
    return 0;
}