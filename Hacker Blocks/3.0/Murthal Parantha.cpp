//pl = Parantha Left; pno = Parantha Number; a = Array of Ratings

#include <iostream>
#include <algorithm>
using namespace std;
int P, L, i, a[100];
long int s, e, mid, ans;

bool chk(long int x)
    {
    long int tim=0, pl=P, pno=1, chef=1;
    do
        {
        if(chef>L)
            return false;
        tim += pno*a[chef-1];
        --pl; ++pno;
        if(tim > x)
            {
            ++pl;
            ++chef;
            tim = 0;
            pno = 1;
            }
        }while(pl>0);
    return true;
    }

int main() {
    cin>>P>>L;
    for(i=0; i<L; i++)
        cin>>a[i];

    sort(a, a+L);
    s = a[1]; e = ((P*(P-1))/2)*a[L-1];
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
