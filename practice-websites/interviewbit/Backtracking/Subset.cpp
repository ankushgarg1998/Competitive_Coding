vector<vector<int> > ans;
int n = 0;

void func(vector<int> &A, int i, vector<int> &s) {
    if(i == n) {
        ans.push_back(s);
        return;
    }
    func(A, i+1, s);
    s.push_back(A[i]);
    func(A, i+1, s);
    s.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    ans.clear();
    n = A.size();
    sort(A.begin(), A.end());
    vector<int> subset;
    func(A, 0, subset);
    sort(ans.begin(), ans.end());
    return ans;
}
