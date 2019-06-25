#include<iostream>
#include<vector>
using namespace std;
int main()
    {
    int t, i, n, count, finalcount;
    long int a[1001];
    cin>>t;
    while(t--)
        {
        finalcount = 0;
        cin>>n;
        for(i=0; i<n; i++)
            {
            count = 0;
            cin>>a[i];
            while(a[i] % 2 == 0)
                {
                ++count;
                a[i] /= 2;
                }
            finalcount += count;
            }
        if(finalcount&1)
            cout<<"Charlie\n";
        else
            cout<<"Alan\n";
        }
    return 0;
    }
