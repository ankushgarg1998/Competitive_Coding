#include <iostream>
using namespace std;



int main()
    {
    int n, m, t, i, j, hours, k;
    cin>>t;
    while(t--)
        {
        int a[110] = {0};
        cin>>n>>m;
        if(n == 1)
            hours = 0;
        else if(n == 2)
            hours = m;
        else
            {
            hours = 0; k = n&1 ? 0:1;
            for(i=n-1; i>0; i = (i==1)? 1:(i-1))
                {
                for(j=n-1; j>=i; j--)
                    {
                    // cout<<i<<" "<<j<<" "<<k<<"\n";
                    // break;
                    if(j%2 == k)
                        {
                        if(a[j] < m)
                            ++a[j];
                        }
                    }
                // for(int x=1; x<n; x++)
                //   cout<<a[x]<<" ";
                // cout<<"\n";
                ++hours;
                k = (k == 0) ? 1:0;
                if(a[1] == m)
                    break;
                // if(i!=1)
                //     --i;
                }
            }
        cout<<hours<<"\n";
        }
    return 0;
    }
