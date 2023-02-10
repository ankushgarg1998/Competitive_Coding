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
    lli p=3, q=11; // two random primes.
    
    // Finding Public Key (e, N)
    lli N = p*q; // modulo part of public key.
    lli phi = (p-1)*(q-1); // Phi(N) = no. of coprimes of N (that are <N)
    // Chose e {1<e<phi(N), e is coprime with phi(N)}
    lli e = 2;
    while(e < phi) {
        if(__gcd(e, phi) == 1)
            break;
        ++e;
    }
    // Public Key = (e, N)

    // Finding the Private Key (d, N)
    // d is the multiplicative inverse of e mod phi(N)
    int k = 1; // a constant value
    while((1+(k*phi)) % e != 0)
        ++k;
    lli d = (1+(k*phi))/e;
    cout<<e<<" "<<d<<"\n\n";

    // Encryption Decryption
    lli msg = 20;
    lli cipher = power(msg, e, N);
    cout<<cipher<<"\n\n";

    lli ret = power(cipher, d, N);
    cout<<ret<<"\n\n";

    return 0;
}