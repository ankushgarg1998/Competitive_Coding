#include<iostream>
#include<cmath>
using namespace std;

string str;

void subseq(string s, int i)
    {
    if(!str[i])
        {
        cout<<s<<" ";
        return;
        }
    subseq(s, i+1);
    subseq(s + str[i], i+1);
    }

int main()
    {
    cin>>str;
    cout<<pow(2, str.size())<<"\n";
    subseq("", 0);
    return 0;
    }
