//HANLDE Sqrt
#include<iostream>
#include<math.h>
using namespace std;
#define test int t; cin>>t; while(t--)

long int A, B, C;

long int testabc(long int a, long int b, long int c)
    {
    // cout<<a<<" "<<b<<" "<<c<<"\n";
    if(a<=A && b<=B && c<=C)
        return 1;
    else
        return 0;
    }

int main()
    {
    long int N, i, j, sqN, x, y, z, M, sqM, ans;
    test
        {
        ans = 0;
        cin>>N>>A>>B>>C;
        sqN = sqrt(N);
        for(i=1; i<=sqN; i++)
            {
            if(N%i == 0)
                {
                x = i;
                M = N/x;
                sqM = sqrt(M);
                for(j=1; j<=sqM; j++)
                    {
                    if(M%j == 0)
                        {
                        y = j;
                        z = M/y;
                        ans += testabc(x, y, z);
                        if(y != z)
                            ans += testabc(x, z, y);
                        }
                    }
                x = N/i;
                //Next Repeat
                if(x != i)
                    {
                    M = N/x;
                    sqM = sqrt(M);
                    for(j=1; j<=sqM; j++)
                        {
                        if(M%j == 0)
                            {
                            y = j;
                            z = M/y;
                            ans += testabc(x, y, z);
                            if(y != z)
                                ans += testabc(x, z, y);
                            }
                        }
                    }
                }
            }
        cout<<ans<<"\n";
        }
    return 0;
    }