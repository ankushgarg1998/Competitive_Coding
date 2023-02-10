#include <iostream>
using namespace std;
int main()
    {
    int t;
    string A;
    cin>>t;
    while(t--)
        {
        cin>>A;
        if(A.size() == 1)
            {
            cout<<"0\n";
            continue;
            }
        long int i=0, majcount=0, count;
        char prev, ldl = '@';
        do
            {
            prev = A[i];
            count = 1;
            ++i;
            while(A[i] == prev)
                {
                ++count;
                ++i;
                }
            // cout<<count;
            majcount += (count*(count-1))/2;
            if(A[i] == ldl)
                ++majcount;
            ldl = prev;
          }while(A[i]);
        cout<<majcount<<"\n";
        }
    return 0;
    }
