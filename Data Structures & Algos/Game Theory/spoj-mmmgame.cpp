#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x, xo=0;
        bool all_one = true;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>x;
            if(x != 1)
                all_one = false;
            xo = xo^x;
        }
        if(all_one)
            cout<<(n&1 ? "Brother": "John");
        else
            cout<<(xo ? "John": "Brother");
        cout<<"\n";
    }
    return 0;
}