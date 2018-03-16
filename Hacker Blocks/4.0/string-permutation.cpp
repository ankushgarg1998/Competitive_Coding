#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

set<string> s;

void permutation(char *str, int x)
    {
    if(strlen(str)-1 == x)
        s.insert(str);
    else
        {
        for(int i=x; i<strlen(str); i++)
            {
            swap(str[x], str[i]);
            permutation(str, x+1);
            swap(str[x], str[i]);
            }
        }
    }

int main()
    {
    char str[10];
    cin>>str;
    permutation(str, 0);
    for(string x:s)
        cout<<x<<"\n";
    return 0;
    }
