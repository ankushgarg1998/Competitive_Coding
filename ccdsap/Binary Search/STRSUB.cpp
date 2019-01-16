#include <bits/stdc++.h>
#define lli long long
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k, q;
        string s;
        cin>>n>>k>>q;
        cin>>s;
        int a[n+10];
        int j=-1, c0=0, c1=0;
        loop(i, 0, n) {
            if(j>=n) {
                a[i] = n-1;
            } else {
                while(c0<=k && c1<=k && j<n) {
                    ++j;
                    if(s[j] == '0')
                        ++c0;
                    else
                        ++c1;
                }
                a[i] = j-1;
            }
            
            if(s[i] == '0')
                --c0;
            else
                --c1;
        }

        lli sum = 0, b[n+10];
        loop(i, 0, n) {
            // cout<<a[i]<<" ";
            sum += (a[i] - i + 1);
            b[i] = sum;
            // cout<<b[i]<<" ";
        }
        while(q--) {
            int p, q;
            cin>>p>>q;
            --p; --q;
            // binary search bw p and q for leftest a[i] > q
            int start = p, end = q, mid = (start+end)/2, ans = q;
            while(start<=end) {
                if(a[mid] >= q) {
                    ans = mid;
                    end = mid-1;
                } else {
                    start = mid+1;
                }
                mid = (start+end)/2;
            }

            lli final_ans = (q-ans+1);
            final_ans = (final_ans*(final_ans+1))/2;

            if(ans != p) {
                lli prev = (p==0? 0: b[p-1]);
                final_ans += (b[--ans] - prev);
            }
            cout<<final_ans<<"\n";
        }
        // 2 2 5 5 5 6 9 7
        // 0 1 1 1 0 0 0 0
        // 0 1 2 3 4 5 6 7
    }
    return 0;
}
