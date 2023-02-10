vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int> > m;
    for(int i=0; i<A.size(); i++) {
        string s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i);
    }
    vector<vector<int> > v(m.size(), vector<int>() );
    int i=0;
    for(auto x: m) {
        for(auto y: x.second) {
            v[i].push_back(y+1);
        }
        ++i;
    }
    return v;
}
