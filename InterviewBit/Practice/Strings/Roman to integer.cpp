int val(char ch) {
    if(ch == 'M')
        return 1000;
    if(ch == 'D')
        return 500;
    if(ch == 'C')
        return 100;
    if(ch == 'L')
        return 50;
    if(ch == 'X')
        return 10;
    if(ch == 'V')
        return 5;
    if(ch == 'I')
        return 1;
}

int Solution::romanToInt(string A) {
    int ans = 0;
    int temp = 0;
    int n = A.size();
    for(int i=n-1; i>=0; i--) {
        if(i<n-1 && val(A[i]) < val(A[i+1])) {
            temp -= val(A[i]);
            ans += temp;
            temp = 0;
        } else {
            temp = val(A[i]);
            ans += temp;
            temp = 0;
        }
    }
    return ans;
}
