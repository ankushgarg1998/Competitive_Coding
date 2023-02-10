#include <iostream>
using namespace std;
int main()
    {
    int t;
    long int d, a;
    cin>>t;
    while(t--)
        {
        cin>>d;
        a = (d % 9)+1;
        cout<<a<<"\n";
        }
    return 0;
    }
