int Solution::colorful(int A) {
    map<long, int> m;
    string s = to_string(A);
    int len = s.size();
    for(int i=0; i<len; i++) {
        for(int j=i; j<len; j++) {
            long x = 1;
            for(int k=i; k<=j; k++)
                x *= (s[k] - '0');
            if(m[x] == 1)
                return 0;
            m[x] = 1;
        }
    }
    return 1;
}
