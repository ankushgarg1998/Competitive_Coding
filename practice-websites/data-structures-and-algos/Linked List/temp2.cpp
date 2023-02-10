#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string isBalanced(string s) {
    // Complete this function
    stack<char> S;
    int i=0;
    while(s[i])
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            S.push(s[i]);
        else
        {
            if(s[i]==S.top())
                S.pop();
            else
                return "NO\n";
        }
    }
    if(S.empty())
        return "YES\n";
    else
        return "NO\n";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}
