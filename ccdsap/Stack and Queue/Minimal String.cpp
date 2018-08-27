#include<iostream>
#include<stack>
#include<map>
using namespace std;

int main() {
    string str, ans="";
    int minn = 27;
    cin>>str;
    map<int, int> m;
    stack<char> s;
    for(char ch: str) {
        int n = ch-'a';
        ++m[n];
        minn = min(n, minn);
    }

    for(char ch: str) {
        s.push(ch);
        int n = ch-'a';
        --m[n];
        while(true) {
            while(!s.empty() && (s.top()-'a' <= minn)) {
                ans += s.top();
                s.pop();
            }
            if(m[minn] == 0) {
                ++minn;
                if(minn>26)
                    break;
            } else
                break;
        }
    }

    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout<<ans<<"\n";
    return 0;
}