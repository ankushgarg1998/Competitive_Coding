vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    int size = B[0].size();
    int ul = A.size()-(size*B.size());
    map<string, int> mf;
    for(string s: B) {
        ++mf[s];
    }
    for(int i=0; i<=ul; i++) {
        string str = A.substr(i, size);
        if(mf[str] > 0) {
            int j = i;
            map<string, int> m;
            while(true) {
                ++m[str];
                j += size;
                if(j>(int)A.size())
                    break;
                str = A.substr(j, size);
                if(m[str] > mf[str])
                    break;
            }
            bool found = true;
            for(string s: B) {
                if(m[s] != 2) {
                    found = false;
                    break;
                }
            }
            if(found)
                ans.push_back(i);
            for(string s: B) {
                m[s] = 1;
            }
        }
    }
    return ans;
}
