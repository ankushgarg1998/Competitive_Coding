#include<iostream>
using namespace std;
int main()
    {
    int t, i, len ,a , b, dot;
    char pre;
    cin>>t;
    while(t--)
        {
        string s;
        cin>>s;
        len = s.size();
        a = 0; b = 0; dot = 0; pre = 'X';
        for(int i=0; i<len; i++)
            {
            if(s[i] == 'A')
                {
                ++a;
                if(dot && pre == 'A')
                    a += dot;
                pre = 'A';
                dot = 0;
                }
            else if(s[i] == 'B')
                {
                ++b;
                if(dot && pre == 'B')
                    b += dot;
                pre = 'B';
                dot = 0;
                }
            else
              ++dot;
            }
        cout<<a<<" "<<b<<"\n";
        }
    return 0;
    }
