#include<iostream>
#include<vector>
#include<set>
using namespace std;

string rec(int i, string s, const vector<vector<char> > &v)
    {
    if(i == L)
        {
        if(a.find(s) != a.end())
            return s;
        }
    }

int main()
    {
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        int N, L;
        string s;
        cin>>N>>L;
        set<string> a;
        vector<vector<char> > v(L);
        for(int i=0; i<N; i++)
            {
            cin>>s;
            for(int j=0; j<L; j++)
                v[j].push_back(s[j]);
            a.insert(s);
            }
        for(int i=0; i<L; i++)
            {
            for(int j=0; j<N; j++)
                {
                rec()
                }
            }
        }
    return 0;
    }