#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int main() {
int t, n, i, j;
long int a[20], sq;
long long int ans;
cin>>t;
while(t--)
    {
    map<int, int> fac;
    cin>>n;
    for(i=0; i<n; i++)
        {
        cin>>a[i];
        for(j=2; j<=a[i]; j++)
            {
            while(a[i]%j == 0)
                {
                ++fac[j];
                a[i] /= j;
                }
            }
        }
    ans =1;
    for(auto it=fac.begin(); it!=fac.end(); ++it)
        ans *= (1+(it->second));
    cout<<ans<<"\n";
    }
return 0;
}
