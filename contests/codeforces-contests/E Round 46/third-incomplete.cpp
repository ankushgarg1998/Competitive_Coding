#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main()
    {
    lli n, l, r;
    vector<pair<lli, int> > v;
    cin>>n;
    vector<lli> c(n+10, 0);
    loop(i, 0, n) {
        cin>>l>>r;
        v.push_back(make_pair(l, 0));
        v.push_back(make_pair(r, 1));
    }
    sort(v.begin(), v.end());

    lli iamat = 0, lastpos = 0;
    lli siamat = n+2, sprev = n+2;
    loop(i, 0, 2*n) {
        c[iamat] += (v[i].first-lastpos-1 > 0 ? v[i].first-lastpos-1 : 0);
        if(v[i].second == 0) {
            ++iamat;
        } else {
            --iamat;
        }
        if(v[i].first == sprev) {
            ++siamat;
        }
        else {
        ++c[siamat];
        sprev = v[i].first;
        siamat = 1;
        }
        lastpos = v[i].first;
    }

    loop(i, 1, n+1) {
        cout<<c[i]<<" ";
    }
    return 0;
    }