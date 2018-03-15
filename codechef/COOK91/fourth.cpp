#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    int N, K, i;
    string s;
    test
        {
        int c=0, ch=0, che=0, chef=0, b[300];
        cin>>N>>K;
        cin>>s;
        for(i=0; i<N; i++)
            {
            switch(s[i])
                {
                case 'c':   ++c;
                            break;
                case 'h':   ch += c;
                            break;
                case 'e':   che += ch;
                            break;
                case 'f':   chef += che;
                            break;
                }
            }
        if(chef < K)
            cout<<"-1\n";
        else if(chef == K)
            cout<<"0\n";
        else
            {
            int f=0, ef=0, hef=0, chef2=0, j;
            for(i=N-1; i>=0; i--)
                {
                switch(s[i])
                    {
                    case 'f':   ++f;
                                b[i] = f;
                                break;
                    case 'e':   ef += f;
                                b[i] = ef;
                                break;
                    case 'h':   hef += ef;
                                b[i] = hef;
                                break;
                    case 'c':   chef2 += hef;
                                b[i] = chef2;
                                j = i;
                                break;
                    }
                }
            cout<<chef<<" "<<j<<"\n";
            for(i=0; i<N; i++)
                cout<<b[i]<<" ";
            cout<<"\n";
            int moves = 0, sum = chef-K;
            for(i=j; i<N; i++)
                {
                if(b[i] <= sum)
                    {
                    ++moves;
                    sum -= b[i];
                    cout<<b[i]<<" ";
                    }
                if(sum == 0)
                    break;
                }
            cout<<"\n\n";
            if(sum == 0)
                cout<<moves<<"\n";
            else
                cout<<"-1\n";
            }
        }
    return 0;
    }