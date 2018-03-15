#include<iostream>
#include<algorithm>
#define test int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    int N, i, j;
    long long int a[710][710], sum, prev, newprev;
    test
        {
        cin>>N;
        for(i=0; i<N; i++)
            {
            for(j=0; j<N; j++)
                cin>>a[i][j];
            sort(a[i], a[i]+N);
            }
        // for(i=0; i<N; i++)
        //     {
        //     for(j=0; j<N; j++)
        //         cout<<a[i][j]<<" ";
        //     cout<<"\n";
        //     }
        sum = a[N-1][N-1];
        prev = a[N-1][N-1];
        newprev = prev;
        for(i=N-2; i>=0; i--)
            {
            for(j=N-1; j>=0; j--)
                {
                if(a[i][j] < prev)
                    {
                    sum += a[i][j];
                    newprev = a[i][j];
                    break;
                    }
                }
            if(newprev == prev)
                {
                sum = -1;
                break;
                }
            prev = newprev;
            }
        cout<<sum<<"\n";
        }
    return 0;
    }
