set<vector<int> > ans;
int n = 0;

void func(vector<int> &A, int i, vector<int> s) {
    if(i == n) {
        ans.insert(s);
        return;
    }
    func(A, i+1, s);
    s.push_back(A[i]);
    func(A, i+1, s);
    s.pop_back();
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    ans.clear();
    n = A.size();
    sort(A.begin(), A.end());
    vector<int> subsets;
    func(A, 0, subsets);
    vector<vector<int> > ans2;
    for(auto g: ans)
        ans2.push_back(g);
    return ans2;
}
