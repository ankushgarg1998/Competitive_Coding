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
    lli p=3, q=11;
    lli N = p*q;
    lli phi = (p-1)*(q-1);
    lli e = 2;
    while(e < phi) {
        if(__gcd(e, phi) == 1)
            break;
        ++e;
    }
    
    int k = 1;
    while((1+(k*phi)) % e != 0)
        ++k;
    lli d = (1+(k*phi))/e;
    cout<<e<<" "<<d<<"\n\n";
    
    lli msg = 13;
    lli cipher = power(msg, e, N);
    cout<<cipher<<"\n\n";

    lli ret = power(cipher, d, N);
    cout<<ret<<"\n\n";

    return 0;
}