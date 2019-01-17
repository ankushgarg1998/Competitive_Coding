#include <bits/stdc++.h>
#define lli long long
#define loop(i, a, b) for(long long i=a; i<b; i++)
using namespace std;
lli X, B, C;

bool func(lli val, lli *x, lli *y, lli *p, lli *q, lli *r) {
    lli i=0, j=0;
    while(i<B && j<C) {
        if(x[i] < p[j]) {
            val -= y[i];
            ++i;
        } else {
            if(q[j] <= val)
                val += r[j];
            ++j;
        }

        if(val <= 0)
            return false;
    }
    while(i<B) {
        val -= y[i];
        if(val <= 0)
            return false;
        ++i;
    }
    if(val>0)
        return true;
    else
        return false;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>X;
        cin>>B;
        lli x[B+10], y[B+10];
        loop(i, 0, B)
            cin>>x[i]>>y[i];
        cin>>C;
        lli p[C+10], q[C+10], r[C+10];
        loop(i, 0, C)
            cin>>p[i]>>q[i]>>r[i];

        // calc
        lli start=0, end=5000000000000000000, mid, ans=end;
        while(start<=end) {
            mid  = (start+end)/2;
            if(func(mid, x, y, p, q, r)) {
                ans = mid;
                end = mid-1;
            } else
                start = mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}