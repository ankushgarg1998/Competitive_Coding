vector<int> Solution::maxset(vector<int> &A) {
    long long sum = 0, maxsum = 0;
    int no=0, ti=-1, tj=-1;
    int maxno=0, maxi=-1, maxj=-2;
    for(int i=0; i<A.size(); i++) {
        if(A[i] >= 0) {
            ti = (ti == -1? i: ti);
            tj = i;
            sum += A[i];
            ++no;
        } else {
            if(sum > maxsum || (sum == maxsum && no>maxno)) {
                maxno = no;
                maxsum = sum;
                maxi = ti;
                maxj = tj;
            }
            no = 0;
            sum = 0;
            ti = -1;
            tj = -1;
        }
    }
    if(sum > maxsum || (sum == maxsum && no>maxno)) {
        maxno = no;
        maxsum = sum;
        maxi = ti;
        maxj = tj;
    }
    vector<int> ans;
    for(int i=maxi; i<=maxj; i++)
        ans.push_back(A[i]);
    return ans;
}
