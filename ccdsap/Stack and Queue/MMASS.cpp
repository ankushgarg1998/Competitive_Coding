#include<iostream>
#include<stack>
using namespace std;
 
int main() {
    string str;
    stack<long long int> s;
    cin>>str;
    for(char ch: str) {
        switch(ch) {
            case '(':   
                s.push(0);
                break;
            case 'C':   
                s.push(12);
                break;
            case 'H':   
                s.push(1);
                break;
            case 'O':   
                s.push(16);
                break;
            case ')': {
                long long int tot=0;
                while(s.top() != 0) {
                    tot += s.top();
                    s.pop();
                }
                s.pop();
                s.push(tot);
            }
                break;
            default: {
                long long int tota = s.top() * (ch-'0');
                s.pop();
                s.push(tota);
            }
                break;
        }
    }
    long long int ans = 0;
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout<<ans<<"\n";
    return 0;
}