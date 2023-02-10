int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int maxxor = A[0] ^ A[1];
    for(int i=1; i<A.size()-1; i++) {
        maxxor = min(A[i]^A[i+1], maxxor);
    }
    return maxxor;
}
