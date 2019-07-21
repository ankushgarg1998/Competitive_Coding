int C(int n, int r) {
    long long x = 1;
    for(int i=0; i<r; i++)
        x *= (n-i);
    for(int i=1; i<=r; i++)
        x /= i;
    return (int)x;
}

int Solution::uniquePaths(int A, int B) {
    int a = max(A-1, B-1);
    int b = min(A-1, B-1);
    
    if(a == 0 || b == 0)
        return 1;
    
    return C(a+b, b);
}
