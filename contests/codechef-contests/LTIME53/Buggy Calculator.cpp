#include <iostream>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    while(t--)
        {
        string a, b;
        cin>>a>>b;
        int sa = a.size(), sb = b.size(), i=0, j=0, ch, x;
        bool firstzero = true;
        if(sa == 1 && sb ==1)
            cout<<((a[i]-'0')+(b[j]-'0'))%10;
        else if(sa > sb)
            {
            ch = sa-sb;
            for(i=0; i<ch; i++)
                {
                if(a[i] != '0')
                    {
                    firstzero = false;
                    cout<<a[i];
                    }
                else if (firstzero == false)
                    cout<<a[i];
                }
            for(j=0; i<sa; i++, j++)
                {
                x = ((a[i]-'0')+(b[j]-'0'))%10;
                if(x != 0)
                    {
                    firstzero = false;
                    cout<<x;
                    }
                else if (firstzero == false)
                    cout<<x;
                }
            }
        else
            {
            ch = sb-sa;
            for(j=0; j<ch; j++)
                {
                if(b[j] != '0')
                    {
                    firstzero = false;
                    cout<<b[j];
                    }
                else if (firstzero == false)
                    cout<<b[j];
                }
            for(i=0; j<sb; i++, j++)
                {
                x = ((a[i]-'0')+(b[j]-'0'))%10;
                if(x != 0)
                    {
                    firstzero = false;
                    cout<<x;
                    }
                else if (firstzero == false)
                    cout<<x;
                }
            }
        cout<<"\n";
        }
    return 0;
    }
