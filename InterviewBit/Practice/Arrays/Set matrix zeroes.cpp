void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<int> rows, cols;
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            if(A[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    for(auto r: rows) {
        for(int j=0; j<A[0].size(); j++) {
            A[r][j] = 0;
        }
    }
    for(auto c: cols) {
        for(int i=0; i<A.size(); i++)
            A[i][c] = 0;
    }
}
