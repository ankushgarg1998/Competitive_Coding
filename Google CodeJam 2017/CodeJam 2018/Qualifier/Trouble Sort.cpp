#include<iostream>
#include<vector>
using namespace std;
int main()
    {
    int test;
    long int N, i;
    string str;
    cin>>test;
    for(int t=1; t<=test; t++)
        {
        cin>>N;
        vector<long int> v(N);
        for(i=0; i<N; i++)
            cin>>v[i];
        bool done = false;
        while(!done)
            {
            done = true;
            for(i=0; i<N-2; i++)
                {
                if(v[i] > v[i+2])
                    {
                    done = false;
                    swap(v[i], v[i+2]);
                    }
                }
            }
        for(i=0; i<N-1; i++)
            {
            if(v[i] > v[i+1])
                break;
            }
        cout<<"Case #"<<t<<": ";
        if(i == N-1)
            cout<<"OK\n";
        else
            cout<<i<<"\n";
        }
    return 0;
    }