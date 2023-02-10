int Solution::solve(vector<int> &A, int B, int C) {
    int ans = 0, n = A.size();
    string c = to_string(C);
    if(c.size() < B)
        return 0;
    if(c.size() > B)
        return (A[0]==0? (B==1? pow(n, B): ((n-1)*pow(n, B-1))): pow(n, B));
        
    int lessThan[110] = {0}, isPresent[100] = {0};
    for(int x: A)
        isPresent[x] = 1;
    int temp = 0;
    for(int i=0; i<11; i++) {
        lessThan[i] = temp;
        temp += isPresent[i];
    }
    
    if(B == 1)
        return lessThan[C];
    
    for(int i=0; i<B; i++) {
        int ci = (c[i] - '0');
        if(i == 0 && isPresent[0] == 1)
            ans += ((lessThan[ci]-1) * pow(n, (B-i-1)));
        else
            ans += (lessThan[ci] * pow(n, (B-i-1)));
        if(isPresent[ci] == 0) {    
            break;
        }
    }
    
    return ans;
}
