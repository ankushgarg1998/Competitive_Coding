#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str;
    stack<char> s;
    cin>>str;
    for(char ch: str) {
        if (!s.empty() && s.top() == ch)
            s.pop();
        else
            s.push(ch);
    }
    if(s.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}