#include <iostream>
using namespace std;
int main()
    {
    int t;
    long int n, k;
    cin>>t;
    while(t--)
        {
        cin>>n>>k;
        if(n==1)
            {
            if(k==0)
                cout<<"0\n";
            else
                cout<<"-1\n";
            }
        }
    return 0;
    }
