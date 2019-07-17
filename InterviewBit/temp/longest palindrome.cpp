string Solution::longestPalindrome(string A) {
    int n = A.size(), maxlen = 0;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    string s = "", ans = "";
    if(n == 0)
        return s;
    if(n == 1)
        return s+A[0];
        
    ans += A[0];
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int i=0; i<n-1; i++) {
        if(A[i] == A[i+1]) {
            dp[i][i+1] = 1;
            if(2>maxlen) {
                maxlen = 2;
                ans = A.substr(i, 2);
            }
        }
    }
    if(n == 2)
        return ans;
        
    for(int l=2; l<n; l++) {
        for(int i=0; i+l<n; i++) {
            int j=i+l;
            if(dp[i+1][j-1] == 1 && A[i] == A[j]) {
                dp[i][j] = 1;
                if(l+1 > maxlen) {
                    ans = A.substr(i, l+1);
                    maxlen = l+1;
                }
            }
        }
    }
    return ans;
}
