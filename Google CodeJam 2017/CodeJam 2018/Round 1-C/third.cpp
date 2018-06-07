#include<iostream>
#include<vector>
#include<set>
using namespace std;

int L;

string rec(string s, int i, const set<string> & a, const vector<set<char> > &v)
    {
    if(i == L)
        {
        if(a.find(s) == a.end())
            return s;
        else
            return "-";
        }
    for(char x:v[i])
        {
        string g = rec(s + x, i+1, a, v);
        if(g != "-")
            return g;
        }
    return "-";
    }

int main()
    {
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        int N, ans = 0;
        set<string> asd;
        string s;
        cin>>N>>L;
        vector<set<char> > v(L);
        for(int i=0; i<N; i++)
            {
            cin>>s;
            asd.insert(s);
            for(int j=0; j<L; j++)
                v[j].insert(s[j]);
            }
        string g;
        if(L != 1)
            {
            g = rec("", 0, asd, v);
            if(g != "-")
                ans = 1;
            }
        if(ans == 0)
            cout<<"Case #"<<test<<": -\n";
        else
            cout<<"Case #"<<test<<": "<<g<<"\n";
        }
    return 0;
    }