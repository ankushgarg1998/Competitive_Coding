#include<iostream>
using namespace std;

int main()
    {
    int t, a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cin>>t;
    while(t--)
        {
        cin>>a1>>a2>>a3;
        cin>>b1>>b2>>b3;
        cin>>c1>>c2>>c3;
        if((a1==b1 && a2==b2 && a3==b3) || (a1==c1 && a2==c2 && a3==c3) || (b1==c1 && b2==c2 && b3==c3))
            cout<<"no\n";
        else if(a1>=b1 && a2>=b2 && a3>=b3)
            {
            if(c1>=a1 && c2>=a2 && c3>=a3)
                cout<<"yes\n";
            else if(b1>=c1 && b2>=c2 && b3>=c3)
                cout<<"yes\n";
            else if(a1>=c1 && a2>=c2 && a3>=c3 && c1>=b1 && c2>=b2 && c3>=b3)
                cout<<"yes\n";
            else
                cout<<"no\n";
            }
        else if(b1>=a1 && b2>=a2 && b3>=a3)
            {
            if(a1>=c1 && a2>=c2 && a3>=c3)
                cout<<"yes\n";
            else if(c1>=b1 && c2>=b2 && c3>=b3)
                cout<<"yes\n";
            else if(b1>=c1 && b2>=c2 && b3>=c3 && c1>=a1 && c2>=a2 && c3>=a3)
                cout<<"yes\n";
            else
                cout<<"no\n";
            }
        else
            cout<<"no\n";
        }
    return 0;
    }
