#include<iostream>
#include<vector>
using namespace std;

int main()
    {
    int m, s, sum;
    cin>>m>>s;
    sum = s;
    if(s==0)
        {
        if(m == 1)
            cout<<"0 0";
        else
            cout<<"-1 -1";
        }
    else if(s > 9*m)
        cout<<"-1 -1";
    else
        {
        // for max
        vector<int> v(m, 0);
        for(int i=0; i<m; i++)
            {
            v[i] = s>=9 ? 9: s;
            s -= v[i];
            cout<<v[i];
            }
        cout<<" ";
        s = sum;
        // for min
        vector<int> u(m, 0);
        u[0] = 1;
        s -= 1;
        for(int i=m-1; i>0; i--)
            {
            u[i] = s>=9 ? 9: s;
            s -= u[i];
            }
        u[0] += s;
        for(auto x: u)
            cout<<x;
        }
    cout<<"\n";
    return 0;
    }