int Solution::singleNumber(const vector<int> &A) {
    int arr[33] = {0};
    for(int x: A) {
        int i=0;
        while(x != 0) {
            arr[i] += (x&1);
            ++i;
            x = x>>1;
        }
    }
    int ans = 0;
    for(int i=0; i<31; i++) {
        ans += (arr[i]%3==0? 0:1)*pow(2, i);
    }
    return ans;
}
