#include <iostream>
#include <algorithm>
using namespace std;
int main()
    {
    int t, N, K, i, a[110];
    cin>>t;
    while(t--)
        {
        cin>>N>>K;
        for(i=0; i<N; i++)
            cin>>a[i];
        sort(a, a+N);
        cout<<a[(N+K-1)/2]<<"\n";
        }
    return 0;
    }
