vector<vector<int> > ans;

void func(vector<int> &x, int i) {
    if(i == x.size()-1) {
        vector<int> g(x);
        ans.push_back(g);
        return;
    }
    // func(x, i+1);
    for(int j=0; i+j<x.size(); j++) {
        swap(x[i], x[i+j]);
        func(x, i+1);
        swap(x[i], x[i+j]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    ans.clear();
    func(A, 0);
    return ans;
}
