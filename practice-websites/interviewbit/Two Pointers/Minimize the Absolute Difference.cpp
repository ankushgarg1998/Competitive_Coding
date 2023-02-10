int ans(int a, int b, int c) {
    return abs(max(a, max(b, c)) - min(a, (min(b, c))));
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {   
    int as = A.size(), bs = B.size(), cs = C.size();
    // int n = min(as, min(bs, cs));
    int mini = INT_MAX;
    int ai=0, bi=0, ci=0;
    while(true) {
        int a=A[ai], b=B[bi], c=C[ci];
        mini = min(mini, ans(a, b, c));
        if(a == b && b == c)
            return 0;
        if(a<=b && a<=c) {
            ++ai;
        } else if(b<=a && b<=c) {
            ++bi;
        } else {
            ++ci;
        }
        if(ai==as || bi==bs || ci==cs)
            break;
    }
    return mini;
}
