#include <iostream>
#include <math.h>
using namespace std;
int main()
    {
    long long int t, Y, a, count;
    long double b;
    cin>>t;
    while(t--)
        {
        cin>>Y;
        count=0;
        // a = sqrt(Y);
        for(int i=1; i<=700; i++)
            {
            if(Y > i)
                {
                b = sqrt(Y-i);
                count += (long long int)b;
                }
            }
        cout<<count<<"\n";
        }
    return 0;
    }
