#include <iostream>
#include<math.h>
#include<string>
using namespace std;
int main() {
    int sb, db, i=0;
    long int n, ans=0;
    char str[50] = {'0'};
    string s;
    cin>>sb>>db>>n;
    if(sb == db)
        cout<<n;
    else if(db == 10)
        {
        while(n!=0)
            {
            ans += (n%10)*pow(sb, i);
            n /= 10;
            ++i;
            }
        cout<<ans;
        }
    else if(sb ==10)
        {
        while(n!=0)
            {
            str[i] = (n%db) + '0';
            ++i;
            n /= db;
            }
        for(--i;i>=0; i--)
            cout<<str[i];
        }
    else if(db == 2)
        {
        s = to_string(n);
        if(sb == 8)
            {
            while(s[i])
                {
                switch(s[i])
                    {
                    case '0': if(i!=0)
                                cout<<"000";
                              break;
                    case '1':   if(i==0)
                                    cout<<"1";
                                else
                                    cout<<"001";
                                break;
                    case '2':   if(i==0)
                                    cout<<"10";
                                else
                                    cout<<"010";
                                break;
                    case '3':   if(i==0)
                                    cout<<"11";
                                else
                                    cout<<"011";
                                break;
                    case '4':   if(i==0)
                                    cout<<"100";
                                else
                                    cout<<"100";
                                break;
                    case '5':   if(i==0)
                                    cout<<"101";
                                else
                                    cout<<"101";
                                break;
                    case '6':   if(i==0)
                                    cout<<"110";
                                else
                                    cout<<"110";
                                break;
                    case '7':   if(i==0)
                                    cout<<"111";
                                else
                                    cout<<"111";
                                break;
                    }
                ++i;
                }
            }
        if(sb == 16)
            {
            while(s[i])
                {
                switch(s[i])
                    {
                    case '0': if(i!=0)
                                cout<<"0000";
                              break;
                    case '1':   if(i==0)
                                    cout<<"1";
                                else
                                    cout<<"0001";
                                break;
                    case '2':   if(i==0)
                                    cout<<"10";
                                else
                                    cout<<"0010";
                                break;
                    case '3':   if(i==0)
                                    cout<<"11";
                                else
                                    cout<<"0011";
                                break;
                    case '4':   if(i==0)
                                    cout<<"100";
                                else
                                    cout<<"0100";
                                break;
                    case '5':   if(i==0)
                                    cout<<"101";
                                else
                                    cout<<"0101";
                                break;
                    case '6':   if(i==0)
                                    cout<<"110";
                                else
                                    cout<<"0110";
                                break;
                    case '7':   if(i==0)
                                    cout<<"111";
                                else
                                    cout<<"0111";
                                break;
                    case '8':   cout<<"1000";
                                break;
                    case '9':   cout<<"1001";
                                break;
                    case 'A':   cout<<"1010";
                                break;
                    case 'B':   cout<<"1011";
                                break;
                    case 'C':   cout<<"1100";
                                break;
                    case 'D':   cout<<"1101";
                                break;
                    case 'E':   cout<<"1110";
                                break;
                    case 'F':   cout<<"1111";
                                break;
                    }
                ++i;
                }
            }
        }
    // else if(sb == 2)
    //     {
    //     s = to_string(n);
    //     if(db == 8)
    //         {
    //         int len = (strlen(s)%3);
    //         if(len == )
    //         }
    //     }
    //     cout<<"lol";
    return 0;
}
