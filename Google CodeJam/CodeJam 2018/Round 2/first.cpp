#include<iostream>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        int C, B[110], ans=0;
        cin>>C;
        for(int i=1; i<=C; i++)
            cin>>B[i];
        
        int left=0, togo[110]={0};
        char grid[110][110];

        if(B[1]==0 || B[C]==0)
            ans = -1;
        else 
            {
            for(int i=0; i<110; i++)
                {
                for(int j=0; j<110; j++)
                    grid[i][j] = '.';
                }
            for(int i=1; i<=C; i++)
                {
                if(B[i] != 0)
                    {
                    left = B[i];
                    for(int j=1; left > 0; j++)
                        {
                        if(togo[j] == 0)
                            {
                            togo[j] = i;
                            --left;
                            }
                        }
                    }
                }

            // for(int i=1; i<=C; i++)
            //     cout<<togo[i]<<" ";

            for(int i=1; i<=C; i++)
                {
                if(togo[i] > i)
                    {
                    ans = max(togo[i]-i, ans);
                    int d=1;
                    for(int j=i; j<togo[i]; j++)
                        {
                        grid[d][j] = '\\';
                        ++d;
                        }
                    }
                if(togo[i] < i)
                    {
                    ans = max(i-togo[i], ans);
                    int d=1;
                    for(int j=i; j>togo[i]; --j)
                        {
                        grid[d][j] = '/';
                        ++d;
                        }
                    }
                }
        }
        if(ans == -1)
            cout<<"Case #"<<test<<": IMPOSSIBLE\n";
        else
            {
            cout<<"Case #"<<test<<": "<<ans+1<<"\n";
            for(int i=1; i<=ans+1; i++)
                {
                for(int j=1; j<=C; j++)
                    {
                    cout<<grid[i][j];
                    }
                cout<<"\n";
                }
            }
        }
    return 0;
    }