#include<iostream>
#include<vector>
using namespace std;
int main()
    {
    int test, A, i, j, x, y;
    cin>>test;
    for(int t=1; t<=test; t++)
        {
        cin>>A;
        if(A != 200)
            {
            vector<vector<int> > v(5, vector<int>(6, 0));
            while(true)
                {
                for(i=2; i<4; i++)
                    {
                    for(j=2; j<5; j++)
                        {
                        if(v[i-1][j-1]==0 || v[i-1][j]==0 || v[i-1][j+1]==0 || v[i][j-1]==0 || v[i][j]==0 || v[i][j+1]==0 || v[i+1][j-1]==0 || v[i+1][j]==0 || v[i+1][j+1]==0)
                            {
                            cout<<i<<" "<<j<<"\n";
                            cin>>x>>y;
                            if(x==-1 || y==-1)
                                return 2;
                            else if(x==0 && y==0)
                                goto jump;
                            else
                                v[x][y] = 1;
                            }
                        }
                    }
                }
            jump:
            ;
            }
        else if(A == 200)
            {
            vector<vector<int> > v(11, vector<int>(21, 0));
            while(true)
                {
                for(i=2; i<10; i++)
                    {
                    for(j=2; j<20; j++)
                        {
                        if(v[i-1][j-1]==0 || v[i-1][j]==0 || v[i-1][j+1]==0 || v[i][j-1]==0 || v[i][j]==0 || v[i][j+1]==0 || v[i+1][j-1]==0 || v[i+1][j]==0 || v[i+1][j+1]==0)
                            {
                            cout<<i<<" "<<j<<"\n";
                            cin>>x>>y;
                            if(x==-1 || y==-1)
                                return 2;
                            else if(x==0 && y==0)
                                goto jump2;
                            else
                                v[x][y] = 1;
                            }
                        }
                    }
                }
            jump2:
            ;
            }
        }
    return 0;
    }