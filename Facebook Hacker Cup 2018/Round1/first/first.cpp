#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

int main() {
    int t, n;
    cin>>t;
    loop(test, 1, t+1) {
        cin>>n;
        char arr[3][1010];
        lli ans = 1;
        loop(j, 0, n)
            cin>>arr[0][j];
        loop(j, 0, n) {
            cin>>arr[1][j];
            if(arr[1][j] == '#')
                ans = 0;
        }
        loop(j, 0, n)
            cin>>arr[2][j];

        if(ans == 0) {
            ans = 0;
        } else if(n&1 != 0) {
            ans = 0;
        } else if(arr[0][0] == '#' || arr[1][0] == '#' || arr[1][n-1] == '#' || arr[2][n-1] == '#') {
            ans = 0;
        } else {
            loops(j, 1, n-1, 2) {
                if(arr[0][j] == '#' || arr[0][j+1] == '#') {
                    if(arr[2][j] == '#' || arr[2][j+1] == '#') {
                        ans = 0;
                        break;
                    }
                } else if(arr[2][j] == '#' || arr[2][j+1] == '#') {
                    continue;
                } else {
                    ans *= 2;
                    ans %= MOD;
                }
            }
        }

        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}