int Solution::lengthOfLongestSubstring(string A) {
    // transform(A.begin(), A.end(), A.begin(), ::tolower); 
    int start = 0, ans = 1;
    vector<int> arr(30000, -1);
    for(int i=0; i<A.size(); i++) {
        int x = A[i] - '0';
        if(arr[x] == -1)
            arr[x] = i;
        else {
            start = max(arr[x]+1, start);
            arr[x] = i;
        }
        ans = max(ans, ((i-start)+1));
    }
    return ans;
}
