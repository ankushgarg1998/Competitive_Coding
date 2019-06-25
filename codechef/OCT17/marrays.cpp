#include<iostream>
#include<vector>
#include<algorithm>
typedef long long int ll;
using namespace std;
int main()
    {
    ll t, n, i, j, m, x, mx, mn;
    cin>>t;
    while(t--)
        {
        cin>>n;
        // vector< vector<int> > v(n);
        // for(i=0; i<n; i++)
        //     {
        //     cin>>m;
        //     v[i].push_back(m);
        //     for(j=0; i<m; j++)
        //         {
        //         cin>>x;
        //         v[i].push_back(x);
        //         }
        //     }
        vector< pair<ll, ll> > v;
        pair<ll, ll> p;
        for(i=0; i<n; i++)
            {
            cin>>m;
            cin>>x;
            mx = x;
            mn = x;
            for(j=1; j<m; j++)
                {
                cin>>x;
                if(x>mx)
                    mx = x;
                if(x<mn)
                    mn = x;
                }
            p = make_pair(mx, mn);
            v.push_back(p);
            }
        cout<<max(abs(v[0].first - v[1].second), abs(v[1].first - v[0].second))<<"\n";
        }
    return 0;
    }
