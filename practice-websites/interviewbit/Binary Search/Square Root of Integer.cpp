int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == 0)
        return 0;
    if(A <= 3)
        return 1;
    int f = 1, l = A, ans = 2;
    while(f<=l) {
        int m = (f+l)/2;
        if(m*m <= A) {
            ans = m;
            if((m+1)*(m+1) > A)
                break;
            f = m+1;
        } else
            l = m-1;
    }
    return ans;
}
