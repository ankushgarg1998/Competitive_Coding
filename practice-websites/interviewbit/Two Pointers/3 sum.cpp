int Solution::threeSumClosest(vector<int> &A, int B) {
    int ans = A[0]+A[1]+A[2], n = A.size();
    if(n == 3)
        return ans;
        
    sort(A.begin(), A.end());
    
    for(int i=0; i<n-2; i++) {
        int r = n-1;
        for(int l=i+1; l<r; l++) {
            int sum = A[i] + A[l] + A[r];
            if(abs(B-sum) < abs(B-ans))
                ans = sum;
            while(sum > B && r>l+1) {
                --r;
                sum = A[i] + A[l] + A[r];
                if(abs(B-sum) < abs(B-ans))
                    ans = sum;
            }
        }
    }
    
    return ans;
}