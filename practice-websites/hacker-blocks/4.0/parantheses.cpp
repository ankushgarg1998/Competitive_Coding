#include<iostream>
using namespace std;
void para(string s, int open, int close)
    {
    if(open==0)
        {
        cout<<s;
        while(close--)
            cout<<")";
        cout<<"\n";
        return;
        }
    if(close)
        para(s+")", open, close-1);
    para(s+"(", open-1, close+1);
    }
int main()
    {
    int n;
    cin>>n;
    para("", n, 0);
    }
