#include <iostream>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>=b; i--)
using namespace std;
int main() {
    test {
        int n;
        cin>>n;
        lli a[n];
        int b[n] = {0};
        loop(i, 0, n)
            cin>>a[i];
        b[n-1] = 0;
        loopr(i, n-2, 0) {
            if(a[i]*a[i+1] < 0)
                b[i] = b[i+1] + 1;
            else
                b[i] = 0;
        }
        loop(i, 0, n)
            cout<<b[i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}