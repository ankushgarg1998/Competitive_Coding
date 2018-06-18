#include<iostream>
#include<cmath>
using namespace std;

long long int fast_exp(long long int base, long long int exp)
{
    if(exp==0)
        return 1;
    if(exp==1)
        return base;
    else
    {
        if(exp%2 == 0)
        {
            long long int base1 = pow(fast_exp(base, exp/2),2);
            if(base1 >= 1000000007)
            return base1%1000000007;
            else
            return base1;
        }
        else
        {
            long long int ans = (base*  pow(fast_exp(base,(exp-1)/2),2));
            if(ans >= 1000000007)
            return ans%1000000007;
            else
            return ans;
        }
    }
}

int main()
    {
    long long int x, k, a, b, c, ans;
    cin>>x>>k;
    if(x == 0)
        {
        cout<<"0\n";
        return 0;
        }
    a = 2*x - 1;
    a %= 1000000007;
    b = fast_exp(2, k);
    c = (a*b) % 1000000007;
    ans = (c+1) % 1000000007;
    cout<<ans<<"\n";
    return 0;
    }