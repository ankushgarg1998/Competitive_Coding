void gc(vector<int> &ans, int n, int &num) {
    if(n == 0) {
        ans.push_back(num);
        return;
    }
    
    gc(ans, n-1, num);
    num = num ^ (1 << (n-1));
    gc(ans, n-1, num);
}

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    if(A == 0)
        return ans;
    int num = 0;
    gc(ans, n, num);
    return ans;
}
