string Solution::convert(string A, int B) {
    if(B == 1)
        return A;
    queue<char> q[B];
    int i=0, diff = 1;
    for(char c: A) {
        if(i == 0)
            diff = 1;
        if(i == B-1)
            diff = -1;
        q[i].push(c);
        i += diff;
    }
    string str = "";
    for(int i=0; i<B; i++) {
        while(!q[i].empty()) {
        str += q[i].front();
        q[i].pop();
        }
    }
    return str;
}
