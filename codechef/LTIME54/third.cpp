#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
    {
    int t, ch;
    long int N, Q, i, X, Y, th, max;
    cin>>t;
    while(t--)
        {
        cin>>N>>Q;
        vector<long int> A(N+1);
        for(i=1; i<=N; i++)
            cin>>A[i];
        while(Q--)
            {
            cin>>ch>>X>>Y;
            if(ch==2)
                A[X] = Y;
            else
                {
                max = LONG_MIN;
                for(i=X; i<=Y; i++)
                    {
                    th = (A[i]-A[X])*(A[Y]-A[i]);
                    if(th > max)
                        max = th;
                    }
                cout<<max<<"\n";
                }
            }
        }
    return 0;
    }
