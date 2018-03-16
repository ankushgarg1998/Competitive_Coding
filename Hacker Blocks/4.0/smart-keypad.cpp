#include<iostream>
using namespace std;

string str, table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void smart(string s, int x)
    {
    if(!str[x])
        {
        cout<<s<<"\n";
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
    return 0;
    }
