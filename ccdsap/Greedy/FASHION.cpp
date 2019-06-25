#include <iostream>
#include <algorithm>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n], b[n];
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n)
            cin>>b[i];

        sort(a, a+n);
        sort(b, b+n);

        long long ans=0;
        loop(i, 0, n)
            ans += (a[i]*b[i]);
        cout<<ans<<"\n";
    }
    return 0;
}

