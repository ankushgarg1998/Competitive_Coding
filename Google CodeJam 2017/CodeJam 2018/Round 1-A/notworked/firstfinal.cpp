#include<iostream>
using namespace std;

int t, R, C, V, H;
char a[110][110];

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
            // for a row (fix temp)
            //     for a col


            }
        else
            cout<<"Case #"<<test<<": IMPOSSIBLE\n";
        }
    return 0;
    }