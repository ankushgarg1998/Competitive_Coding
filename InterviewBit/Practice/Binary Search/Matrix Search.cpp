int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int f=0, l = A.size()-1, ans = -1;
    while(f<=l) {
        int m = (f+l)/2;
        int z = A[m].size()-1;
        if(A[m][0] > B)
            l = m-1;
        else if(A[m][z] < B)
            f = m+1;
        else {
            ans = m;
            break;
        }
    }
    if(ans == -1)
        return 0;
    int h = ans;
    f = 0, l = A[ans].size()-1, ans = -1;
    while(f<=l) {
        int m = (f+l)/2;
        if(A[h][m] > B)
            l = m-1;
        else if(A[h][m] < B)
            f = m+1;
        else {
            ans = m;
            break;
        }
    }
    if(ans == -1)
        return 0;
    else
        return 1;
}
