#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long n, x, xo=0;
        cin>>n;
        for(long i=1; i<=n; i++) {
            cin>>x;
            if(x&1 != 0)
                xo = xo^i;
        }
        if(xo != 0)
            cout<<"Tom Wins\n";
        else
            cout<<"Hanks Wins\n";
    }
    return 0;
}