//PRETTYPRINT

vector<vector<int> > Solution::prettyPrint(int A) {
    int n = (2*A)-1;
    vector<vector<int> > v(n, vector<int>(n));
    if(n == 1) {
        v[0][0] = 1;
        return v;
    }
        
    for(int i=0; i<A; i++) {
        for(int j=0; j<A; j++) {
            v[i][j] = max(A-j, A-i);
        }
        for(int j=A-1; j>0; j--) {
            v[i][n-j] = max(A+1-j, A-i);
        }
    }
    for(int i=A-1; i>0; i--) {
        for(int j=0; j<A; j++) {
            v[n-i][j] = max(A-j, A+1-i);
        }
        for(int j=A-1; j>0; j--) {
            v[n-i][n-j] = max(A+1-j, A+1-i);
        }
    }
    return v;
}
