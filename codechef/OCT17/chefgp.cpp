#include <iostream>
typedef long int li;
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
        {
        string s;
        li x, y, len, a=0, b=0, i;
        cin>>s;
        cin>>x>>y;
        len = s.length();
        for(i=0; i<len; i++)
            {
            if(s[i] == 'a')
                ++a;
            else
                ++b;
            }
        if(a>=b)
            {
	while(b!= 0)
                {
                cout<<"a";
                --a;
                cout<<"b";
                --b;
                }
            while(a!=0)
                {
                cout<<"a";
                --a;
                if(a)
                    cout<<"*";
                }
            }
        else
            {
	while(a!= 0)
                {
                cout<<"b";
                --b;
                cout<<"a";
                --a;
                }
            while(b!=0)
                {
                cout<<"b";
                --b;
                if(b)
                    cout<<"*";
                }
            }
        cout<<"\n";
        }
    return 0;
}

