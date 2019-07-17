int longestPalin(string A, float x) {
    int i = floor(x), j = ceil(x), n = A.size();
    int len = 0;
    while(i>=0 && j<n) {
        if(A[i] == A[j]) {
            len += (i == j? 1: 2);
        } else
            return len;
        --i; ++j;
    }
    return len;
}

string Solution::longestPalindrome(string A) {
    int n = A.size(), maxlen = 1;
    string ans = "";
    if(n == 0)
        return ans;
    ans += A[0];
    if(n == 1)
        return ans;
    for(float i=0.5; i<n-1; i+=0.5) {
        int l = longestPalin(A, i);
        if(l > maxlen) {
            if(floor(i) == ceil(i)) {
                ans = A.substr(floor(i) - (l/2), l);
            } else {
                ans = A.substr(ceil(i) - (l/2), l);
            }
            maxlen = l;
        }
    }
    return ans;
}
