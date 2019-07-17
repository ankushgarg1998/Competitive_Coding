int Solution::lengthOfLastWord(const string A) {
    int len = 0, prev = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == ' ') {
            prev = (len==0?prev:len);
            len = 0;
        } else
            ++len;
    }
    return (len==0?prev:len);
}