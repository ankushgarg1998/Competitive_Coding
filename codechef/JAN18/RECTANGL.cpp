#define test int t; cin>>t; while(t--)
#include<iostream>
using namespace std;
int main()
    {
    int a, b, c, d;
    test
        {
        cin>>a>>b>>c>>d;
        if(a == b)
            {
            if(c == d)
                cout<<"YES";
            else
                cout<<"NO";
            }
        else if(a == c)
            {
            if(b == d)
                cout<<"YES";
            else
                cout<<"NO";
            }
        else if(a == d)
            {
            if(b == c)
                cout<<"YES";
            else
                cout<<"NO";
            }
        else
            cout<<"NO";
        cout<<"\n";
        }
    return 0;
    }
