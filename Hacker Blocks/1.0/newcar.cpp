#include<iostream>
typedef long long int ll;
ll mod = 1000000007;
using namespace std;

ll stringToInt(string str, ll m)
    {
    ll ans =0, i=0;
    while(str[i])
        {
        ans = (ans*10)%m + (str[i]-'0');
        ans %= m;
        ++i;
        }
    // cout<<ans<<"\n";
    return ans;
    }

ll power(ll x, ll y)
    {
    if(y == 0)
        return 1;
    else
        {
        ll smallPower = power(x, y/2)%mod;
        smallPower = (smallPower*smallPower)%mod;
        if(y%2 != 0)
            return (x*smallPower)%mod;
        return smallPower;
        }
    }
    
int main() {
    int t;
    string A, B;
    ll a, b;
    cin>>t;
    while(t--)
        {
        cin>>A>>B;
        a = stringToInt(A, mod);
        b = stringToInt(B, mod-1);
        // cout<<a<<" "<<b;
        cout<<power(a, b);
        }
	return 0;
}
