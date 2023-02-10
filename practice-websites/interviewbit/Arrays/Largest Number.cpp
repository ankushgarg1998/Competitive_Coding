bool func(string a, string b) {
    if(a.rfind(b, 0) == 0) {
        string s1 = "", s2 = "";
        return (s1+a+b)>(s2+b+a);
    }
    if(b.rfind(a, 0) == 0) {
        string s1 = "", s2 = "";
        return (s1+a+b)>(s2+b+a);
    }
    return a>b;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    for(int x: A)
        v.push_back(to_string(x));
    
    sort(v.begin(), v.end(), func);
    string ans = "";
    if(stoi(v[0]) == 0)
        return "0";
    for(string str: v)
        ans += str;
    return ans;
}
