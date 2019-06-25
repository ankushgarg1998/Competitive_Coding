#include<iostream>
#include<vector>
using namespace std;

int main()
    {
    string s;
    cin>>s;
    vector<int> v(s.size(), 0);
    for(int i=1; i<s.size(); i++)
        {
        if(s[i-1] == s[i])
            {
            v[i] = v[i-1]+1;
            }
        else
            v[i] = v[i-1];
        // cout<<v[i]<<" ";
        }
    int n, a, b;
    cin>>n;
    for(int i=0; i<n; i++)
        {
        cin>>a>>b;
        cout<<v[b-1] - v[a-1]<<"\n";
        }
    return 0;
    }