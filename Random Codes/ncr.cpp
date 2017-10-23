#include <iostream>
#define mod 1000000007
using namespace std;

long long int fac(long long int x, long long int y=1)
    {
    long long int z = 1;
for(long long int i = y; i <=x; i++)
        {
        z *= i;
        z %= mod;
        }
    return z;
    }

int main() {
    long long int n, r;
    cin>>n>>r;
    if (n/2 > r)
        cout<<fac(n, n-r+1)/fac(r);
    else
        cout<<fac(n, r+1)/fac(n-r);
    return 0;
}
