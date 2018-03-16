#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string str;

void subseq(string s, int i)
    {
    if(!str[i])
        {
        if(s.size() == str.size())
            cout<<s;
        else
            cout<<", "<<s;
        return;
        }

    subseq(s + (char)((str[i]-'0')+96), i+1);
    if(str[i+1])
        {
        if(stoi(str.substr(i,2)) <= 26)
            subseq(s + (char)(stoi(str.substr(i,2))+96), i+2);
        }
    }

int main()
    {
    cin>>str;
    cout<<"[";
    subseq("", 0);
    cout<<"]";
    return 0;
    }
