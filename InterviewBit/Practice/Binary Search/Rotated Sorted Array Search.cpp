int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if(n == 1) {
        return (A[0]==B? 0: -1);
    }
    
    int f=0, l=A.size()-1, ans=0, m;
    while(f <= l) {
        m = (f+l)/2;
        if(A[m]>A[(m+1)%n]) {
            ans = m;
            break;
        }
        if(A[m] < A[f])
            l = m-1;
        else
            f = m+1;
    }
    if(A[ans] == B)
        return ans;
    if(ans == n-1) {
        f = 0;
        l = n-1;
    } else if(B <= A[n-1]) {
        f = ans + 1;
        l = n-1;
    } else {
        f = 0;
        l = ans;
    }
    while(f <= l) {
        m = (f+l)/2;
        if(A[m] == B)
            return m;
        if(A[m] < B)
            f = m+1;
        else
            l = m-1;
    }
    return -1;
}
