#include <iostream>
#include <algorithm>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    while(t--)
        {
        string a;
        bool solved = false;
        cin>>a;
        long int i=0, n=a.size(), sum=0, ans = -1;
        for(i=0; i<n; i++)
            sum += (a[i]-'0');

        if((a[n-1]-'0')&1)
            {
            if((a[n-2]-'0')&1)
                cout<<"-1\n";
            else
                {
                if(((sum - (a[n-1]-'0'))%3) == 0)
                    {
                    for(i=0; i<n-1; i++)
                        cout<<a[i];
                    cout<<"\n";
                    }
                else
                    cout<<"-1\n";
                }
            }
        else
            {
            // sort(a.begin(), a.end());
            // cout<<sum<<endl;
            for(i=0; i<n-1; i++)
                {
                if((sum - (a[i]-'0'))%3 == 0)
                    {
                    ans = i;
                    if(a[i+1] > a[i])
                        break;
                    }
                }
            if(ans != -1)
                {
                if(a[ans+1] > a[ans])
                    {
                    solved = true;
                    for(i=0; i<n; i++)
                        {
                        if(i != ans)
                            cout<<a[i];
                        }
                    cout<<"\n";
                    }
                }
            if(solved == false)
                {
                if((((sum - (a[n-1]-'0'))%3) == 0) && ((a[n-2]&1) == 0))
                    ans = n-1;
                if(ans == -1)
                    cout<<"-1\n";
                else
                    {
                    for(i=0; i<n; i++)
                        {
                        if(i != ans)
                            cout<<a[i];
                        }
                    cout<<"\n";
                    }
                }
            }
        }
    return 0;
    }
