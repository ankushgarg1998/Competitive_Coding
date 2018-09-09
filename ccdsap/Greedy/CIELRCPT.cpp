#include <iostream>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int p, ans = 0;
        cin>>p;
        int x = 2048;
        while(x > 0) {
            ans += (p/x);
            p %= x;
            x /= 2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}