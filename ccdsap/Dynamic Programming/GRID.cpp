#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>=b; i--)
using namespace std;

int main() {
    test {
        int n;
        cin>>n;
        char a[1010][1010];
        loop(i, 0, n) {
            loop(j, 0, n)
                cin>>a[i][j];
        }
        loop(j, 0, n) {
            loopr(i, n-1, 0) {
                if(a[i][j] == '.')
                    a[i][j] = 'd';
                else
                    break;
            }
        }
        int ans = 0;
        loop(i, 0, n) {
            loopr(j, n-1, 0) {
                if(a[i][j] == 'd')
                    ++ans;
                else if(a[i][j] == '#')
                    break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}