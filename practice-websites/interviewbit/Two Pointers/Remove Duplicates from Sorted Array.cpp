int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return 0;
    int j = 1;
    for(int i=1; i<A.size(); i++) {
        if(A[i] != A[j-1]) {
            A[j] = A[i];
            ++j;
        }
    }
    A.resize(j);
    return j;
}
