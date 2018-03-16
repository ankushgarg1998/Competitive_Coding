#include<iostream>
#include<math.h>
typedef long long int ll;
using namespace std;
ll hi, n, count;
bool should;

ll height(ll x)
    {
    return (pow(2, x+1)-1);
    }

void tra(ll s, ll e, char step, ll h)
    {
    if(should)
        ++count;
    if(s==e)
        {
        if(s==n)
            should = false;
        return;
        }
    if(step == 'L')
        {
        if(n <= ((s+e)/2))
            tra(s, (s+e)/2, 'R', h-1);
        else
            {
            count += height(h-1);
            tra(((s+e)/2)+1, e, 'L', h-1);
            }
        }
    else
        {
        if(n > ((s+e)/2))
            tra(((s+e)/2)+1, e, 'L', h-1);
        else
            {
            count += height(h-1);
            tra(s, (s+e)/2, 'R', h-1);
            }
        }
    }

int main() {
    int t;
    cin>>t;
    while(t--)
        {
        long long int full;
        cin>>hi>>n;
        count=0; should = true;
        full = pow(2, hi);
        tra(1, full, 'L', hi);
        cout<<count-1<<"\n";
        }
	return 0;
}
