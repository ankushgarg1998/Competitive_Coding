#include<iostream>
using namespace std;
typedef long long int ll;

ll fac(ll x, ll y=1)
    {
    ll z = 1;
    for(ll i = y; i <=x; i++)
        {
        z *= i;
        // z %= mod;
        }
    return z;
    }

ll nCr(ll n, ll r)
    {
    if(n == r)
        return 1;
    if(n == 1)
        return 0;
    if (n/2 > r)
        return fac(n, n-r+1)/fac(r);
    else
        return fac(n, r+1)/fac(n-r);
    }

int main() {
    ll N, M, kmax, kmin;
    cin>>N>>M;
    if(N <= M)
        cout<<"0 0\n";
    //1 ka case
    //find (N-M+1) C 2,    M-1((N/M) C 2)   + (N/M + N%M) C 2
    // if(M == 1)
    //     {
    //     cout<<nCr(N, 2)<<" "<<nCr(N, 2)<<"\n";
    //     }
    else
        {
        kmax = nCr((N-M+1), 2);
        kmin = ( ((M-(N%M))*(nCr((N/M), 2))) + ((N%M)*nCr((N/M)+1, 2)) );
        cout<<kmin<<" "<<kmax<<"\n";
        }
	return 0;
}
