#include <iostream>
using namespace std;
int main()
    {
    int t, N, A, i;
    string whoa = "aababb";
    cin>>t;
    while(t--)
        {
        cin>>N>>A;
        if(A==1)
            {
            cout<<N<<" ";
            for(i=0; i<N; i++)
                cout<<"a";
            }
        else if(A==2)
            {
            if(N==1)
                cout<<"1 a";
            else if(N==2)
                cout<<"1 ab";
            else if(N==3)
                cout<<"2 abb";
            else if(N==4)
                cout<<"2 aabb";
            else if(N==5)
                cout<<"3 aaaba";
            else if(N==6)
                cout<<"3 aaabab";
            else if(N==7)
                cout<<"3 aaababb";
            else if(N==8)
                cout<<"3 aaababbb";
            else
                {
                cout<<"4 a";
                --N;
                for(i=0; i<(N/6); i++)
                    cout<<whoa;
                for(i=0; i<(N%6); i++)
                    cout<<whoa[i];
                }
            }
        else
            {
            cout<<"1 ";
            for(i=0; i<(N/3); i++)
                cout<<"abc";
            if(N%3 == 1)
                cout<<"a";
            else if(N%3 == 2)
                cout<<"ab";
            }
        cout<<"\n";
        }
    return 0;
    }
