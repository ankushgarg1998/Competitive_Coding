string Solution::simplifyPath(string A) {
    vector<string> v;
    string s = "";
    for(int i=0; i<A.size(); i++) {
        if(A[i] == '/') {
            if(s != "") {
                if(s == ".." && v.size()>0) {
                    v.pop_back();
                } else if(s != "." && s != "..") {
                    v.push_back(s);
                }
            }
            s = "";
        } else
            s += A[i];
    }
    s = (v.size()==0? "/":"");
    for(string a: v) {
        s += "/";
        s += a;
    }
    return s;
}
