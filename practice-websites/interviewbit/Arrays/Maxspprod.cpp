int Solution::maxSpecialProduct(vector<int> &A) {
    if(A.size() < 4)
        return 0;
    int n = A.size();
    vector<int> l(n), r(n);
    stack<pair<int, int> > s, s2;
    for(int i=0; i<n; i++) {
        while(!s.empty() && s.top().first <= A[i])
            s.pop();
        if(s.empty())
            l[i] = 0;
        else
            l[i] = s.top().second;
        s.push(make_pair(A[i], i));
    }
    for(int i=n-1; i>=0; i--) {
        while(!s2.empty() && s2.top().first <= A[i])
            s2.pop();
        if(s2.empty())
            r[i] = 0;
        else
            r[i] = s2.top().second;
        s2.push(make_pair(A[i], i));
    }
    
    long long maxa = 0;
    for(int i=0; i<n; i++)
        maxa = max(maxa, (long long)l[i]*(long long)r[i]);
    return (int)(maxa%1000000007);
}
