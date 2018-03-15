#include<iostream>
#include<math.h>
using namespace std;

int main()
    {
    double t, n, sig, i;
    cin>>t;
    while(t--)
        {
        double ans;
        cin>>n>>sig;
        ans = sqrt((sig*sig)*n/2);
        cout<<ans<<" "<<-1*ans<<" ";
        for(i=0; i<(n-2); i++)
            cout<<"0 ";
        }
    return 0;
    }
