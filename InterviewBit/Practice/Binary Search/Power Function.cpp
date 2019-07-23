int powe(long long x, long long n, long long d) {
    if(n == 0)
        return 1;
    x %= d;
    long long ans = 1;
    while(n > 0) {
        if(n&1)
            ans = (ans*x)%d;
        n>>=1;
        x = (x*x)%d;
    }
    return (int)ans;
}

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = powe((long long)x, (long long)n, (long long)d)%d;
    return (ans < 0? ans+d: ans);
}
