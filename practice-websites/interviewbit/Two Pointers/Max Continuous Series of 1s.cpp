vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    vector<int> zeroes;
    zeroes.push_back(-1);
    for(int i=0; i<n; i++) {
        if(A[i] == 0)
            zeroes.push_back(i);
    }
    zeroes.push_back(n);
    int temp = zeroes.size()-1;
    int f = 0, l = min(f+B+1, temp);
    int maxlen = 0, ansf=0, ansl=0;
    for(; l<=temp; f++, l++) {
        int len = (zeroes[l]-zeroes[f]-1);
        if(len > maxlen) {
            maxlen = len;
            ansf = zeroes[f]+1;
            ansl = zeroes[l];
        }
    }
    vector<int> ans;
    for(int i=ansf; i<ansl; i++)
        ans.push_back(i);
    return ans;
}
