#include<iostream>
using namespace std;
int main()
    {
    int t, R, C, V, H;
    char a[110][110];
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        cin>>R>>C>>H>>V;
        int choco=0, ans = 1;
        int chocoHr[110] = {0}, chocoVr[110] = {0};

        for(int i=0; i<R; i++)
            {
            chocoHr[i] = 0;
            for(int j=0; j<C; j++)
                {
                cin>>a[i][j];
                if(a[i][j] == '@')
                    {
                    ++choco;
                    ++chocoHr[i];
                    }
                }
            }
        
        for(int j=0; j<C; j++)
            {
            for(int i=0; i<R; i++)
                {
                if(a[i][j] == '@')
                    chocoVr[j] += 1;
                } 
            }
        
        if(choco == 0)
            cout<<"Case #"<<test<<": POSSIBLE\n";
        else if(choco % ((V+1)*(H+1)) == 0)
            {
            int cookiesPerDiner = choco / ((V+1)*(H+1));
            int chocoPerRow = choco / (H+1);
            int chocoPerCol = choco / (V+1);

            for(int i=0; i<R; i++)
                {
                int kstart = i, kend;
                int chocoRow = 0;
                while(chocoRow < chocoPerRow && i<R)
                    {
                    chocoRow += chocoHr[i];
                    ++i;
                    kend = i;
                    }
                --i;
                if(chocoRow > chocoPerRow)
                    {
                    ans = 0;
                    break;
                    }
                else
                    {
                    int finalChoco = 0;
                    for(int j=0; j<C; j++)
                        {
                        int chocoCol = 0, chkJugaad=0, jstart=j, jend;
                        while(chocoCol < cookiesPerDiner && j<C)
                            {
                            int net = 0;
                            for(int k=kstart; k<kend; k++)
                                {
                                if(a[k][j] == '@')
                                    ++net;
                                }
                            chocoCol += net;
                            ++j;
                            jend = j;
                            }
                        --j;
                        if(chocoCol > cookiesPerDiner)
                            {
                            ans = 0;
                            break;
                            }
                        else
                            {
                            finalChoco += chocoCol;
                            for(int k=jstart; k<jend; k++)
                                chkJugaad += chocoVr[k];
                            if(chkJugaad > chocoPerCol)
                                {
                                ans = 0;
                                break;
                                }
                            }
                        }
                    if(finalChoco != chocoPerRow)
                        {
                        ans = 0;
                        break;
                        }
                    }
                if(ans == 0)
                    break;
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