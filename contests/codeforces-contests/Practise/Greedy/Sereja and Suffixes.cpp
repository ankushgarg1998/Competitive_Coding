#include<iostream>
#include<vector>
using namespace std;

int main()
    {
    int n, m, x;
    cin>>n>>m;
    vector<int> v(n), freq(100001, 0), ans(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    ans[n-1] = 1;
    freq[v[n-1]] = 1;
    for(int i=n-2; i>=0; i--)
        {
        if(freq[v[i]] == 0)
            {
            ans[i] = ans[i+1]+1;
            freq[v[i]] = 1;
            }
        else
            ans[i] = ans[i+1];
        }
    for(int i=0; i<m; i++)
        {
        cin>>x;
        cout<<ans[x-1]<<"\n";
        }
    return 0;
    }