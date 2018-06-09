#include<iostream>
using namespace std;
int main()
    {
    int test;
    long int D;
    string str;
    cin>>test;
    for(int t=1; t<=test; t++)
        {
        cin>>D>>str;
        long int charge = 1, damage = 0, ans = 0, arr[40]={0};
        for(int i=0; i<str.length(); i++)
            {
            if(str[i] == 'C')
                charge *= 2;
            else
                {
                arr[i] = charge;
                damage += charge;
                }
            }
        if(damage <= D)
            ans = 0;
        else
            {
            for(int i=str.length()-1; i>0; i--)
                {
                if(str[i] == 'S' && str[i-1] == 'C')
                    {
                    arr[i] /= 2;
                    damage -= (arr[i]);
                    swap(str[i], str[i-1]);
                    swap(arr[i], arr[i-1]);
                    ++ans;
                    i = str.length();
                    if(damage <= D)
                        break;
                    }
                }
            }
        if(damage <= D)
            cout<<"Case #"<<t<<": "<<ans;
        else
            cout<<"Case #"<<t<<": IMPOSSIBLE";
        cout<<"\n";
        }
    return 0;
    }