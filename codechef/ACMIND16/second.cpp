#include <iostream>
using namespace std;
int main()
    {
    long int t, n, i, a[100001];
    cin>>t;
    while(t--)
        {
        bool ans = true, plus1 = false, zero = false;
        int pos = 0, neg = 0, min1 = 0;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            {
            if(a[i] > 1)
                {
                ++pos;
                if(pos > 1)
                    {
                    ans = false;
                    break;
                    }
                }
            else if(a[i] < -1)
                {
                ++neg;
                if(neg > 1)
                    {
                    ans = false;
                    break;
                    }
                }
            else if(a[i] == -1)
                ++min1;
            else if(a[i] == 1)
                plus1 = true;
            else if(a[i] == 0)
                zero = true;
            }
        if(ans == false)
            cout<<"no\n";
        else
            {
            if(pos != 0 && neg != 0)
                cout<<"no\n";
            else if(min1 > 1 && plus1 == false)
                cout<<"no\n";
            else if(neg > 0 && min1 > 0)
                cout<<"no\n";
            else if(pos > 0 && min1 > 0)
                cout<<"no\n";
            else
                cout<<"yes\n";
            }
        }
    return 0;
    }
