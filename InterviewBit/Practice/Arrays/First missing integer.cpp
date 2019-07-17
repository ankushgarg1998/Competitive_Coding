int Solution::firstMissingPositive(vector<int> &A) {
    if(A.size() == 1)
        return (A[0] == 1? 2: 1);
    int last = false;
    for(int i=0; i<A.size(); i++) {
        int x = A[i];
        if(x != INT_MAX) {
            here:
            if(x == A.size()) {
                last = true;
            }
            if(x>0 && x< A.size()) {
                int y = A[x];
                A[x] = INT_MAX;
                if(y != INT_MAX) {
                    x = y;
                    goto here;
                }
            }
        }
    }
    
    for(int i=1; i<A.size(); i++) {
        if(A[i] != INT_MAX)
            return i;
    }
    return A.size() + (last? 1: 0);
}
