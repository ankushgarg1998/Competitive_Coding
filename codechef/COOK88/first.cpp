#include <iostream>
#include <iomanip>
using namespace std;
int main()
    {
    int t, n, i, j, a[110];
    double ans;
    cin>>t;
    while(t--)
        {
        cin>>n;
        int max = 0, secmax = 0, countmax = 0, countsecmax=0;
        for(i=0; i<n; i++)
            {
            cin>>a[i];
            if(a[i] == max)
                ++countmax;
            else if(a[i] == secmax)
                ++countsecmax;
            else if(a[i] > max)
                {
                secmax = max;
                max = a[i];
                countsecmax = countmax;
                countmax = 1;
                }
            else if(a[i] > secmax)
                {
                secmax = a[i];
                countsecmax = 1;
                }
            }
        if(countmax > 1)
            ans = countmax*(countmax-1)/2;
        else
            ans = countsecmax;

        // cout<<countmax<<" "<<countsecmax<<"\n";
        cout<<fixed<<setprecision(8)<<ans/(n*(n-1)/2)<<"\n";
        }
    return 0;
    }
