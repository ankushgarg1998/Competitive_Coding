#include<iostream>
#include<vector>
#include<climits>
typedef long long int lli;
using namespace std;
int main()
    {
    int t, n, q, i;
    unsigned long long int val, min, x;
    cin>>t;
    while(t--)
        {
        cin>>n;
        vector<lli> a0(n);
        vector<lli> a1(n);
        vector<lli> a2(n);
        vector<lli> a3(n);
        for(i=0; i<n; i++)
            cin>>a0[i]>>a1[i]>>a2[i]>>a3[i];
        cin>>q;
        while(q--)
            {
            cin>>x;
            min = ULLONG_MAX;
            for(i=0; i<n; i++)
                {
                val = a0[i] + (a1[i]*x) + (a2[i]*x*x) + (a3[i]*x*x*x);
                if(val<min)
                    min = val;
                }
            cout<<min<<"\n";
            }
        }
    return 0;
    }
