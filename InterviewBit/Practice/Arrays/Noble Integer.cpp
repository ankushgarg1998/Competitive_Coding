int Solution::solve(vector<int> &A) {
    if(A.size() == 1) {
        if(A[0] == 0)
            return 1;
        else
            return -1;
    }
    sort(A.begin(), A.end());
    vector<int> B(A.size());
    B[A.size()-1] = 0;
    int count = 1;
    for(int i=A.size()-2; i>=0; i--) {
        if(A[i] == A[i+1]) {
            B[i] = B[i+1];
            ++count;
        }
        else {
            B[i] = B[i+1] + count;
            count = 1;
        }
    }
    for(int i=A.size()-1; i>=0; i--) {
        if(A[i] == B[i])
            return 1;
    }
    return -1;
}
