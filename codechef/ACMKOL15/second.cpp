#include <iostream>
#include <climits>
using namespace std;
int main()
    {
    int t, rowsum, N, M, i, j, p, q, val, minsum, thissum, ans;
    int a[1010][1010];
    cin>>t;
    while(t--)
        {
        cin>>N>>M;
        //initialize with 0
        ans = INT_MAX;
        for(i=0; i<N; i++)
            {
            for(j=0; j<M; j++)
                cin>>a[i][j];
            }
        for(i=0; i<N; i++)
            {
            for(j=0; j<M; j++)
                {
                val = a[i][j];
                minsum = 0;
                thissum = 0;
                for(q=j+1; q<M; q++)
                    {
                    thissum += a[i][q];
                    if(thissum < minsum)
                        minsum = thissum;
                    }
                val += minsum;
                minsum = 0;
                thissum = 0;
                for(q=j-1; q>=0; q--)
                    {
                    thissum += a[i][q];
                    if(thissum < minsum)
                        minsum = thissum;
                    }
                val += minsum;
                minsum = 0;
                thissum = 0;
                for(p=i+1; p<N; p++)
                    {
                    thissum += a[p][j];
                    if(thissum < minsum)
                        minsum = thissum;
                    }
                val += minsum;
                minsum = 0;
                thissum = 0;
                for(p=i-1; p>=0; p--)
                    {
                    thissum += a[p][j];
                    if(thissum < minsum)
                        minsum = thissum;
                    }
                val += minsum;

                if(val < ans)
                    ans = val;
                }
            }
        cout<<ans<<"\n";
        }
    return 0;
    }
