bool isPalinE(int x, string s) {
    int i=0;
    while(x-i >= 0) {
        if(s[x-i] != s[x+i+1])
            return false;
        ++i;
    }
    return true;
}

bool isPalinO(int x, string s) {
    int i=0;
    while(x-i >= 0) {
        if(s[x-i] != s[x+i])
            return false;
        ++i;
    }
    return true;
}

int Solution::solve(string A) {
    int n = A.size();
    if(n%2 == 0) {
        for(int i=(n/2)-1; i>=0; i--) {
            if(isPalinE(i, A))
                return (n - (2*(i+1)));
            if(isPalinO(i, A))
                return (n - ((2*i)+1));
        }
    } else {
        for(int i=(n-1)/2; i>=0; i--) {
            if(isPalinO(i, A))
                return (n - ((2*i)+1));
            if(isPalinE(i-1, A))
                return (n - (2*(i+1)));
        }
    }
}
