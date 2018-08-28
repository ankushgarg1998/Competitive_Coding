#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin>>str;
    stack<int> s;
    int base = 0, maxmax = 0, count = 0;
    for(char ch: str) {
        if(s.empty() && ch == ')') {
            if(maxmax == base)
                ++count;
            else if(base > maxmax) {
                maxmax = base;
                count = 1;
            }
            base = 0;
        } else if (ch == '(') {
            s.push(0);
        } else {
            int n = s.top();
            s.pop();
            if(s.empty()) {
                base += (n+1);
            } else {
                n += (s.top()+1);
                s.pop();
                s.push(n);
            }
        }
    }
    if(maxmax == base)
        ++count;
    else if(base > maxmax) {
        maxmax = base;
        count = 1;
    }
    while(!s.empty()) {
        if(s.top() == maxmax) {
            ++count;
        } else if(s.top() > maxmax) {
            maxmax = s.top();
            count = 1;
        }
        s.pop();
    }
    cout<<2*maxmax<<" "<<(maxmax == 0? 1: count)<<"\n";
    return 0;
}