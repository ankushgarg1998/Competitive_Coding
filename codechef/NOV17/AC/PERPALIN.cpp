#include <iostream>
using namespace std;
int main()
    {
    int t, N, P, i, j;
    cin>>t;
    while(t--)
        {
        cin>>N>>P;
        if(P<3)
            cout<<"impossible\n";
        else
            {
            for(i=0; i<(N/P); i++)
                {
                cout<<"a";
                for(j=0; j<(P-2); j++)
                    cout<<"b";
                cout<<"a";
                }
            cout<<"\n";
            }
        }
    return 0;
    }
