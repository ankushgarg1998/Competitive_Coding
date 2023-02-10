#include <iostream>
#include <algorithm>
using namespace std;
int k, n, i;
long long int a[11], sum = 0, s, e, mid, ans, maxi=0;

bool chk(long long int x)
    {
    long long int all=0; int painter=1;
    for(i=0; i<n; i++)
        {
        if(painter>k)
            return false;
        all += a[i];
        if(all > x)
            {
            --i;
            ++painter;
            all = 0;
            }
        }
    return true;
    }

int main() {
    cin>>k>>n;
    for(i=0; i<n; i++)
        {
        cin>>a[i];
        if(a[i]>maxi)
            maxi = a[i];
        sum += a[i];
        }
    // sort(a, a+n);
    s = maxi; e = sum;
    while(s<=e)
        {
        mid = (s+e)/2;
        // cout<<mid<<" "<<chk(mid)<<" ";
        if(chk(mid))
            {
            ans = mid;
            e = mid-1;
            }
        else
            s = mid+1;
        }
    cout<<ans;
    return 0;
}
