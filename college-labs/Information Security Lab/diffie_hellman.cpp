#include<bits/stdc++.h>
#define lli long long
using namespace std;

lli power(lli x, lli p, lli mod) {
    lli ans = 1;
    while(p--) {
        ans *= x;
        ans %= mod;
    }
    return ans;
}

int main() {
    lli n = 100, g = 2; // n is the upper limit and g is the common base
    lli a = 6; //alice's private key
    lli b = 9; // bob's private key

    lli ag = power(g, a, n); // alice's public key
    lli bg = power(g, b, n); // bob's public key
    cout<<ag<<" "<<bg<<"\n\n";

    lli agb = power(bg, a, n);
    lli bga = power(ag, b, n);
    cout<<agb<<" "<<bga<<"\n\n";

    return 0;
}