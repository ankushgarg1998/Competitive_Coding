vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> G;
    stack<int> s;
    for(int x: A) {
        while(true) {
            if(s.empty()) {
                G.push_back(-1);
                break;
            }
            if(s.top() < x) {
                G.push_back(s.top());
                break;
            }
            s.pop();
        }
        s.push(x);
    }
    return G;
}
