//INCORRECT
#include <iostream>
using namespace std;
int main()
    {
    long int t, n, i, a[100001];
    cin>>t;
    while(t--)
        {
        long int temp=0, pos=0, count=0;
        bool ans = true, pres = false;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            {
            if(a[i] == -1 && count == 0)
                {
                ++pos;
                ++count;
                if(pos > 1)
                    {
                    ans = false;
                    break;
                    }
                }
            if(a[i] != 0 && a[i] != 1 && a[i] != -1)
                {
                ++pos;
                if(pos > 1)
                    {
                    ans = false;
                    break;
                    }
                }
            }
        if(ans == false)
            cout<<"no\n";
        else
            cout<<"yes\n";
        }
    return 0;
    }
