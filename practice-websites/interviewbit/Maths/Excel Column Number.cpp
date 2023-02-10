int Solution::titleToNumber(string A) {
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        char ch = A[A.size()-1-i];
        int no = (ch-'A')+1;
        ans += (no*pow(26, i));
    }
    return ans;
}
