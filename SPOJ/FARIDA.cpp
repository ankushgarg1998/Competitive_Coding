#include<iostream>
using namespace std;
int main()
    {
    int test;
    cin>>test;
    for(int t=1; t<=test; t++)
        {
        int N;
        long int a[10001][2];
        cin>>N;
        for(int i=0; i<N; i++)
            cin>>a[i][0];
        a[0][1] = a[0][0];
        if(N == 0)
            {
            cout<<"Case "<<t<<": 0\n";
            continue;
            }
        if(N == 1)
            {
            cout<<"Case "<<t<<": "<<a[N-1][1]<<"\n";
            continue;
            }
        a[1][1] = max(a[0][0], a[1][0]);
        for(int i=2; i<N; i++)
            a[i][1] = max(a[i-1][1], a[i][0]+a[i-2][1]);
        cout<<"Case "<<t<<": "<<a[N-1][1]<<"\n";
        }
    return 0;
    }