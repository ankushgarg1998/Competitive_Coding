#include<bits/stdc++.h>
#define lli long long int
#define loop(i, a, b) for(long long int i=a; i<b; i++)
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int test=1; test<=t; test++) {
        lli n, k, v;
        cin>>n>>k>>v;
        vector<string> A(n);
        loop(i, 0, n)
            cin>>A[i];

        cout<<"Case #"<<test<<": ";
        lli x = ((v-1)*k)%n;
        if(n-x < k) {
            lli z = k - (n-x);
            loop(y, 0, z)
                cout<<A[y]<<" ";
        }
        while(k-- && x<n) {
            cout<<A[x]<<" ";
            ++x;
        }
        cout<<"\n";
    }
    return 0;
}