#include<iostream>
using namespace std;
int main()
    {
    int n, k, i;
    cin>>n>>k;
    if(k%2 == 0)
        {
        cout<<"YES\n";
        for(i=0; i<n; i++)
            cout<<".";
        cout<<"\n.";
        
        for(i=0; i<(k/2); i++)
            cout<<"#";
        for(; i<n-1; i++)
            cout<<".";
        cout<<"\n.";

        for(i=0; i<(k/2); i++)
            cout<<"#";
        for(; i<n-1; i++)
            cout<<".";
        cout<<"\n";

        for(i=0; i<n; i++)
            cout<<".";
        cout<<"\n";
        }
    else
        {
        if(k >= n-2)
            {
            cout<<"YES\n";
            for(i=0; i<n; i++)
                cout<<".";
            cout<<"\n.";

            for(i=0; i<n-2; i++)
                cout<<"#";
            cout<<".\n.";

            for(i=0; i<(k+2-n)/2; i++)
                cout<<"#";
            for(i=0; i<(2*n-k-4); i++)
                cout<<".";
            for(i=0; i<(k+2-n)/2; i++)
                cout<<"#";
            cout<<".\n";

            for(i=0; i<n; i++)
                cout<<".";
            cout<<"\n";
            }
        else
            {
            cout<<"YES\n";
            for(i=0; i<n; i++)
                cout<<".";
            cout<<"\n.";

            for(i=0; i<(k-1)/2; i++)
                cout<<"#";
            for(i=0; i<(n-k-1); i++)
                {
                if(i == ((n-k-1)/2))
                    cout<<"#";
                else
                    cout<<".";
                }
            for(i=0; i<(k-1)/2; i++)
                cout<<"#";
            cout<<".\n";

            for(i=0; i<n; i++)
                cout<<".";
            cout<<"\n";

            for(i=0; i<n; i++)
                cout<<".";
            cout<<"\n";
            }
        }
    return 0;
    }