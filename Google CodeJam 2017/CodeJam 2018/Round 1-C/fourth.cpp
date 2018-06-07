#include<iostream>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        int N, D, a[210][210];
        bool ice[210];
        int prob[210]={0};
        cin>>N;
        for(int i=0; i<N; i++)
            ice[i] = true;
        for(int i=0; i<N; i++)
            {
            int sold = 0;
            cin>>D;
            if(D == -1)
                return 1;
            for(int j=0; j<D; j++)
                {
                cin>>a[i][j];
                ++prob[a[i][j]];
                if(a[i][j] == -1)
                    return 1;
                }
            int pro = 300, sell = -1;
            for(int j=D-1; j>=0; j--)
                {
                if(ice[a[i][j]] && prob[a[i][j]] < pro)
                    {
                    sell = a[i][j];
                    pro = prob[a[i][j]];
                    // cout<<a[i][j]<<"\n";
                    // ice[a[i][j]] = false;
                    sold = 1;
                    }
                }
            if(sold == 0)
                cout<<"-1\n";
            else
                {
                cout<<sell<<"\n";
                ice[sell] = false;
                }
            }
        }
    return 0;
    }