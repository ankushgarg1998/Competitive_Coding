#include<iostream>
using namespace std;

int t, R, C, V, H;
char a[110][110];

bool chk(int P, int Q)
    {
    int quad1=0, quad2=0, quad3=0, quad4=0;
    for(int i=0; i<P; i++)
        {
        for(int j=0; j<Q; j++)
            {
            if(a[i][j] == '@')
                ++quad1;
            }
        }
    for(int i=0; i<P; i++)
        {
        for(int j=Q; j<C; j++)
            {
            if(a[i][j] == '@')
                ++quad2;
            }
        }
    for(int i=P; i<R; i++)
        {
        for(int j=0; j<Q; j++)
            {
            if(a[i][j] == '@')
                ++quad3;
            }
        }
    for(int i=P; i<R; i++)
        {
        for(int j=Q; j<C; j++)
            {
            if(a[i][j] == '@')
                ++quad4;
            }
        }
    if(quad1==quad2 && quad2==quad3 && quad3==quad4)
        return true;
    else
        return false;
    }

int main()
    {
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        cin>>R>>C>>H>>V;
        int choco=0, ans = 0;

        for(int i=0; i<R; i++)
            {
            for(int j=0; j<C; j++)
                {
                cin>>a[i][j];
                if(a[i][j] == '@')
                    ++choco;
                }
            }
        
        if(choco == 0)
            cout<<"Case #"<<test<<": POSSIBLE\n";
        else if(choco % ((V+1)*(H+1)) == 0)
            {
            int cookiesPerDiner = choco / ((V+1)*(H+1));
            int chocoPerRow = choco / (H+1);
            int chocoPerCol = choco / (V+1);

            for(int i=1; i<R; i++)
                {
                for(int j=1; j<C; j++)
                    if(chk(i, j))
                        {
                        ans = 1;
                        break;
                        }
                }

            if(ans == 0)
                cout<<"Case #"<<test<<": IMPOSSIBLE\n";
            else
                cout<<"Case #"<<test<<": POSSIBLE\n";
            }
        else
            cout<<"Case #"<<test<<": IMPOSSIBLE\n";
        }
    return 0;
    }