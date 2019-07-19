int Solution::isPalindrome(int A) {
    if(A<0)
        return 0;
    string s = to_string(A);
    int i=0, j=s.size()-1;
    while(i<j) {
        if(s[i] != s[j])
            return 0;
        ++i; --j;
    }
    return 1;
}
