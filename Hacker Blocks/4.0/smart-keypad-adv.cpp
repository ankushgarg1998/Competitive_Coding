#include<iostream>
#include<vector>
using namespace std;

string str, table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
vector<string> v;
void smart(string s, int x)
    {
    if(!str[x])
        {
        // cout<<s<<"\n";
        v.push_back(s);
        return;
        }
    int i=0;
    while(table[(str[x]-'0')][i])
        {
        smart(s+table[(str[x]-'0')][i], x+1);
        ++i;
        }
    }

int main()
    {
    cin>>str;
    smart("", 0);
    for(string s:searchIn)
        {
        for(string ye:v)
            {
            if(s.find(ye)!=string::npos)
                cout<<s<<"\n";
            }
        }
    return 0;
    }
