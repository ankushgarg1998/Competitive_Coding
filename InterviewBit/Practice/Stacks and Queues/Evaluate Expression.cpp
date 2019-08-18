int Solution::evalRPN(vector<string> &A) {
    stack<long long> s;
    for(string str: A) {
        // cout<<(s.empty()? 0:s.top())<<"\n";
        long long x, y;
        if(str == "+") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(x+y);
        } else if(str == "-") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(y-x);
        } else if(str == "*") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(x*y);
        } else if(str == "/") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(y/x);
        } else {
            int c = stoi(str);
            s.push((long long)c);
        }
    }
    return (int)s.top();
}
