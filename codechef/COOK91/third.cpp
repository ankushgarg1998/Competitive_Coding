#include<iostream>
#include<algorithm>
#define test int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    long int N, k, b, i, j, a[100001], min, maximum, ans1, ans2;
    test
        {
        ans1 = 1;
        ans2 = 1;
        cin>>N>>k>>b;
        for(i=0; i<N; i++)
            cin>>a[i];
        sort(a, a+N);
        // for(i=0; i<N; i++)
        //     cout<<a[i];
        min = a[0];
        maximum = (k*min) + b;
        for(i=1; i<N; i++)
            {
            if(a[i] >= maximum)
                {
                // cout<<min<<" ";
                min = a[i];
                j = i;
                maximum = (k*min) + b;
                ans1 += 1;
                }
            }
        cout<<ans1<<"\n";
        }
    return 0;
    }