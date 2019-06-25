#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    test {
        int n, m, x, y;
        cin>>n>>m>>x>>y;
        int blocks = n*m;
        lli ans1=0, ans2=0;
        loop(i, 1, n+1) {
            loop(j, 1, m+1) {
                int possible = blocks - (m+n-1);
                int upar = (i-1);
                int niche = (n-i);
                int left = (j-1);
                int right = (m-j);

                int d1 = min(left, upar);
                int d2 = min(right, upar);
                int d3 = min(right, niche);
                int d4 = min(left, niche);

                possible -= (d1+d2+d3+d4);

                // cout<<possible<<" ";
                ans1 += possible;
                if(i == x && j == y)
                    ans1 -= (2*possible);
            }
            // cout<<"\n";
        }
        // cout<<"ans1 = "<<ans1<<"\n";

        int i=x, j=y;

        int upar = (i-1);
        int niche = (n-i);
        int left = (j-1);
        int right = (m-j);

        int d1 = min(left, upar);
        int d2 = min(right, upar);
        int d3 = min(right, niche);
        int d4 = min(left, niche);

        ans2 += (left*right);
        ans2 += (upar*niche);
        ans2 += (d1*d3);
        ans2 += (d2*d4);

        // cout<<"ans2 = "<<ans2<<"\n";
        ans2 *= 2;

        lli ans = ans1 + ans2;
        cout<<ans<<"\n";
    }
    return 0;
}