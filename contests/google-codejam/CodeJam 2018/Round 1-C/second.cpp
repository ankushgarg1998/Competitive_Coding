#include<iostream>
#include<vector>
#include<set>
using namespace std;

int L;

string rec(string s, int i, const set<string> & a)
    {
    if(i == L)
        {
        if(a.find(s) == a.end())
            return s;
        else
            return "-";
        }
    for(string x:a)
        {
        string g = rec(s + x[i], i+1, a);
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
        for(int i=0; i<N; i++)
            {
            cin>>s;
            asd.insert(s);
            }
        string g;
        if(L != 1)
            {
            g = rec("", 0, asd);
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