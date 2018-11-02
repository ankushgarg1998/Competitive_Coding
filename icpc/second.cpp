#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main()
    {
    test {
        int n, k;
        cin>>n>>k;
        int a[60], b[60];

        loop(i, 0, n) {
            cin>>a[i];
            b[i] = a[i];
        }

        if(n == 1) {
            cout<<a[0]<<"\n";
            continue;
        }
        sort(a, a+n);

        // int m = a[n-1];
        
        li ans = 0;
        do {
            loop(i, 0, n-1) {
                if(a[i] != -1) {
                    if(a[i] <= k) {
                        ans += a[i];
                        a[i] = -1;
                    }
                }
            }

            int mi = INT_MAX, ma = 0;
            int mii = -1, mai = -1;
            for(int i=0; i<n-1; i++) {
                if(a[i] != -1) {
                    if(a[i] < mi) {
                        mi = a[i];
                        mii = i;
                    }
                }
            }

            for(int i=n-2; i>=0; i--) {
                if(a[i] != -1) {
                    if(a[i] > ma) {
                        ma = a[i];
                        mai = i;
                    }
                }
            }
            
            if(mii == mai) {
                if(mii == -1) {
                    ans += a[n-1];
                } else {
                int dif = a[mii] - k;
                a[mii] = -1;
                ans += k;
                ans += (a[n-1] - dif);
                }
                break;
            } else {
                int dif = a[mii] - k;
                a[mii] -= dif;
                a[mai] -= dif;
            }
        } while(true);

        cout<<ans<<"\n";
    }
    return 0;
    }