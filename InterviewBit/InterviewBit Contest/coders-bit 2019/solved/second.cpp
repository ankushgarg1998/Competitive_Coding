string Solution::solve(string A) {
    set<string> s;
    for(int j=0; j<A.size(); j++) {
        for(int i=j; i<A.size(); i++) {
            if(A[i] <= A[j]) {
                string g = string(A);
                reverse(g.begin()+j, g.begin()+i+1);
                s.insert(g);
            }
        }
    }
    string ans = *s.begin();
    return ans;
}
