vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int mod = 1000000007;
    vector<pair<int, long long int> > a;
    
    sort(A.begin(), A.end());
    
    long long int ini=0;
    for(auto num: A) {
        // cout<<num<<" ";
        int ans = 1; // prod_of_divisors
        int sq = sqrt(num);
        // cout<<sq<<"\n";
        for(int i=1; i<sq; i++) {
            if(num%i == 0) {
                ans *= i;
                ans %= mod;
                ans *= (num/i);
                ans %= mod;
            }
        }
        if(sq*sq == num) {
            ans *= sq;
            ans  %= mod;
        } else if(num%sq == 0) {
            ans *= sq;
            ans %=mod;
            ans *=(num/sq);
            ans %= mod;
        }
        ++ini;
        a.push_back(make_pair(ans, ini));
    }
    
    sort(a.rbegin(), a.rend());
    
    int len = a.size();
    for(int i=1; i<len; i++) {
        a[i].second += a[i-1].second;
    }
    
    for(auto z: a) {
        cout<<z.first<<" "<<z.second<<"\n";
    }
    vector<int> res;
    for(int q: B) {
        long long int first = 0, last = len-1, mid;
        int response;
        while(first <= last) {
            mid = (first + last)/2;
            if(q <= a[mid].second) {
                response = a[mid].first;
                last = mid-1;
            } else {
                first = mid+1;
            }
        }
        // res.push_back(response);
    }
    return res;
}
