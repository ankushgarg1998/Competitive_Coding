#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define test int t; cin>>t; while(t--)
using namespace std;
int n, k;

int main()
    {
    vector<vector<vector<int> > > a(10);
    for(int i=1; i<=8; i++)
        {
        vector<int> c;
        for(int j=1; j<=i; j++)
            c.push_back(j);
        do
            {
            a[i].push_back(c);
            }while(next_permutation(c.begin(), c.end()));
        // for(auto x: a[i])
        //     {
        //     for(auto y: x)
        //         cout<<y<<" ";
        //     cout<<"\n";
        //     }
        }

    test
        {
        cin>>n>>k;
        int count = 0;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];

        for(auto x:a[n])
            {
            int i=0;
            for(i=0; i<n; i++)
                {
                if(x[i] != v[i] && v[i] != 0)
                    break;
                }
            if(i==n)
                {
                int countk = 0;
                for(int i=1; i<n; i++)
                    {
                    if(x[i] > x[i-1])
                        ++countk;
                    }
                if(countk == k)
                    ++count;
                }
            }
        cout<<count<<"\n";
        }
    return 0;
    }