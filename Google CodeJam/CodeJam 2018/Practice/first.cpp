#include<iostream>
using namespace std;
int main()
    {
    int t, N;
    long long int A, B;
    string s;
    cin>>t;
    while(t--)
        {
        cin>>A>>B;
        cin>>N;
        ++A;
        while(N--)
            {
            cout<<(A+B)/2<<endl;
            cin>>s;
            if(s == "CORRECT")
                break;
            else if(s == "TOO_SMALL")
                A = ((A+B)/2)+1;
            else if(s == "TOO_BIG")
                B = ((A+B)/2)-1;
            else
                return 3;
            }
        }
    return 0;
    }