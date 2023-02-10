#include<iostream>
#include<map>
#include<stack>
using namespace std;

map<char, int> m;

void mappy() {
    m.insert(make_pair('+', 1));
    m.insert(make_pair('-', 2));
    m.insert(make_pair('*', 3));
    m.insert(make_pair('/', 4));
    m.insert(make_pair('^', 4));
}

int main() {
    mappy();
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        stack<char> ch;

        for(int i=0; i<s.size(); i++) {
            if(m[s[i]] != 0) {
                while(!ch.empty() && (m[ch.top()] > m[s[i]])) {
                    cout<<ch.top();
                    ch.pop();
                }
                ch.push(s[i]);
            } else if(s[i] == '(') {
                ch.push('(');
            } else if(s[i] == ')') {
                while(ch.top() != '(') {
                    cout<<ch.top();
                    ch.pop();
                }
                ch.pop();
            } else {
                cout<<s[i];
            }
        }
        
        while(!ch.empty()) {
            cout<<ch.top();
            ch.pop();
        }
        cout<<"\n";
    }
    return 0;
}