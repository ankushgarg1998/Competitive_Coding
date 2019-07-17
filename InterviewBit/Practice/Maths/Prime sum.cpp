vector<int> Solution::primesum(int A) {
    vector<bool> prime(A+10, true);
    for(long int i=2; i<=A; i++) {
        if(prime[i]) {
            for(long int j=i*i; j<=A; j+=i)
                prime[j] = false;
        }
    }
    
    vector<int> ans;
    for(int i=2; i<A; i++) {
        if(prime[i] && prime[A-i]) {
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
}
