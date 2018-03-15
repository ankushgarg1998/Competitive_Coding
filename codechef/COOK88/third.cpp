//base cases
#include <iostream>
#include<vector>
using namespace std;
int main()
    {
    long int t, n, m, i, j, counti, countj, prev;
    cin>>t;
    while(t--)
        {
        cin>>n>>m;
        vector<vector<long int> > a(n, vector<long int>(m));
        vector<vector<int> > b(n, vector<int>(m, 0));
        for(i=0; i<n; i++)
            {
            for(j=0; j<m; j++)
                cin>>a[i][j];
            }
        counti = 0;
        if(m == 1)
            {
            if(n == 1)
                counti = 1;
            prev = a[0][0];
            countj = 0;
            for(i=1; i<n; i++)
                {
                if(a[i][j] != prev)
                    ++countj;
                prev = a[i][j];
                }
            counti += countj;
            }
        else
            {
            for(i=0; i<n; i++)
                {
                prev = a[i][0];
                countj = 0;
                for(j=1; j<m; j++)
                    {
                    if(a[i][j] > prev)
                        {
                        ++countj;
                        b[i][j] = 1;
                        }
                    else if(a[i][j] < prev)
                        {
                        ++countj;
                        b[i][j-1] = 1;
                        }
                    prev = a[i][j];
                    }
                counti += countj;
                }
            // cout<<counti<<" ";
            for(j=0; j<m; j++)
                {
                prev = a[0][j];
                countj = 0;
                for(i=1; i<n; i++)
                    {
                    if(a[i][j] == prev && b[i][j] == 1)
                        ++countj;
                    // else
                    //     {
                    //     counti -= countj;
                    //     countj = 0;
                    //     }
                    prev = a[i][j];
                    }
                counti -= countj;
                }
            }
        cout<<counti<<"\n";
        }
    return 0;
    }
