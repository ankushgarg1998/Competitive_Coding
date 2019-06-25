#include <bits/stdc++.h>
#define lli long long
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        lli sum = 0, a[n+10] = {0}, b[n+10] = {0}, c[n+10] = {0};
        loop(i, 1, n+1) {
            cin>>a[i];
            sum += a[i];
            b[i] = min(a[i], b[i-1]+1);
        }
        for(int i=n; i>0; i--) {
            c[i] = min(a[i], c[i+1]+1);
        }

        lli maxi = 0;
        loop(i, 1, n+1) {
            maxi = max(maxi, min(b[i], c[i]));
        }
        cout<<sum+maxi-(maxi*(maxi+1))<<"\n";
    }
    return 0;
}