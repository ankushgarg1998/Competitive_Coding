#include<iostream>
#include<stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        stack<char> ch;
        int ans = 0, i;
        for(i=0; i<s.size(); i++) {
            if(ch.empty())
                ans = i;
            if(s[i] == '<')
                ch.push('<');
            else if(ch.empty())
                break;
            else if(ch.top() == '<')
                ch.pop();
            else
                break;
        }
        if(ch.empty())
                ans = i;
        cout<<ans<<"\n";
    }
    return 0;
}