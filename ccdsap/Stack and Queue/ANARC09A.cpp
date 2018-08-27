#include<iostream>
#include<stack>
using namespace std;

int main() {
    int t=0;
    while(true) {
        ++t;
        string s;
        cin>>s;
        stack<char> stac;
        int ans=0;
        if(s[0] == '-')
            break;
        for(char ch: s) {
            if(ch == '{') {
                stac.push('{');
            } else {
                if(stac.empty()) {
                    ++ans;
                    stac.push('{');
                } else {
                    stac.pop();
                }
            }
        }
        cout<<t<<". "<<ans+(stac.size()/2)<<"\n";
    }
    return 0;
}