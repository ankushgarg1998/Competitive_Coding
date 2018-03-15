#include <iostream>
using namespace std;
class chess
    {
    public:
    long int Ri, Mini, Maxi;
    int Timei, isRatedi, Colori;
    }ch[110];
int main()
    {
    int t, match, i, j, n;
    string a;
    cin>>t;
    while(t--)
        {
        cin>>n;
        bool used[110];
        for(i=0; i<n; i++)
            used[i] = false;
        for(i=0; i<n; i++)
            {
            cin>>ch[i].Ri>>ch[i].Mini>>ch[i].Maxi>>ch[i].Timei;
            cin>>a;
            if(a == "rated")
                ch[i].isRatedi = 1;
            else
                ch[i].isRatedi = 0;
            cin>>a;
            if(a == "black")
                ch[i].Colori = 0;
            else if(a == "white")
                ch[i].Colori = 1;
            else
                ch[i].Colori = 3;
            match = -1;
            for(j=0; j<i; j++)
                {
                if(!used[j])
                    {
                    if(ch[i].Timei == ch[j].Timei)
                        {
                        if(ch[i].isRatedi == ch[j].isRatedi)
                            {
                            if((ch[i].Colori==0 && ch[j].Colori==1) || (ch[i].Colori==1 && ch[j].Colori==0) || (ch[i].Colori==3 && ch[j].Colori==3))
                                {
                                if(ch[j].Mini <= ch[i].Ri && ch[i].Ri <= ch[j].Maxi)
                                    {
                                    if(ch[i].Mini <= ch[j].Ri && ch[j].Ri <= ch[i].Maxi)
                                        {
                                        match = j;
                                        used[j] = true;
                                        used[i] = true;
                                        break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            if(match == -1)
                cout<<"wait\n";
            else
                cout<<match+1<<"\n";
            }
        }
    return 0;
    }
