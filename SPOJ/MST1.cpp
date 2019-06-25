#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main()
    {
    int T;
    vector<int> a(20000005, INT_MAX);
    a[0] = 0;
    a[1] = 0;
    for(int i=1; i<=20000000; i++)
        {
        a[i+1] = min(a[i]+1, a[i+1]);
        if(i<=10000000)
            a[i*2] = min(a[i]+1, a[2*i]);
        if(i<=6666667)
            a[i*3] = min(a[i]+1, a[3*i]);
        }
    cin>>T;
    for(int i=1; i<=T; i++)
        {
        int N;
        cin>>N;
        cout<<"Case "<<i<<": "<<a[N]<<"\n";
        }
    return 0;
    }