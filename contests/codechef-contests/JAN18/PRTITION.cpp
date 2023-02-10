#include<iostream>
#define test long int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    long long int i, x, N, s;
    int a[1000010];
    test
        {
        cin>>x>>N;
        s = N*(N+1);
        s /= 2;
        s -= x;
        if(s&1 || N<4)
            cout<<"impossible";
        else
            {
            s /= 2;
            for(i=N; i>0; i--)
                {
                if (i == x)
                    a[i] = 2;
                else if(s>=i)
                    {
                    if(s-i == x && x <= 2)
                        a[i] = 0;
                    else
                        {
                        a[i] = 1;
                        s -= i;
                        }
                    }
                else
                    a[i] = 0;
                }
            if(s != 0)
                cout<<"impossible";
            else
                {
                for(i=1; i<=N; i++)
                    cout<<a[i];
                }
            }
        cout<<"\n";
        }
    return 0;
    }
