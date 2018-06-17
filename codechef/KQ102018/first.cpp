#include<iostream>
using namespace std;

int main()
    {
    string s;
    cin>>s;
    long int ans = 1;
    for(int i=0; i<s.size(); i++)
        {
        if(s[i] == '*')
            {
            if(i%2 == 0)
                {
                ans *= 21;
                }
            else
                ans *= 5;
            }
        }
    cout<<ans<<"\n";
    return 0;
    }