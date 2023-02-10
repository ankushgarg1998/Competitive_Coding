#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test long long int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

vector<lli> prim;

void SieveOfEratosthenes(vector<bool> &prime, lli n)
{
	for (lli p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
            prim.push_back(p);
			// Update all multiples of p
			for (lli i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}
}

lli leg(lli n) {
    lli ans = 0;
    lli i = 0;
    while(prim[i] <= n){
        lli k = prim[i];
        while(k <= n) {
            ans += (n/k);
            k *= prim[i];
        }
        ++i;
    }
    // sq
    return ans;
}

int main()
    {
    vector<bool> prime(5000010, true);
    SieveOfEratosthenes(prime, 5000001);
    test {
        lli a, b, ans = 0;
        cin>>a>>b;
        cout<<leg(a) - leg(b)<<"\n";
    }
    // cout<<prim[0];
    return 0;
    }