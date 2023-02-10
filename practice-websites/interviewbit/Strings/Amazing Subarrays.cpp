int Solution::solve(string A) {
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        char c = A[i];
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            ans += (A.size() - i);
            ans %= 10003;
        }
    }
}
