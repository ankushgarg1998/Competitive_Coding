#include <iostream>
using namespace std;
int main()
    {
    int t, l;
    string a;
    cin>>t;
    while(t--)
        {
        cin>>a;
        int count = 0;
        l = a.size();
        for(int i=0; i<l; i++)
            {
            if(a[i]>='0' && a[i]<='9')
                count += (a[i] - '0');
            }
        cout<<count<<"\n";
        }
    return 0;
    }
