#include<iostream>
using namespace std;
int main()
    {
    int t, R, C, V, H, i, j;
    char a[110][110];
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        cin>>R>>C>>H>>V;
        int choco=0;
        for(i=0; i<R; i++)
            {
            for(j=0; j<C; j++)
                {
                cin>>a[i][j];
                if(a[i][j] == '@')
                    ++choco;
                }
            }
        }
    }