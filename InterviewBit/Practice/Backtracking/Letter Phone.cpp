vector<string> ans;

void func(string A, int i, string s, vector<vector<char> > &v) {
    if(i == A.size()) {
        ans.push_back(s);
        return;
    }
    int x = A[i] - '0';
    for(char ch: v[x]) {
        string g = s;
        g += ch;
        func(A, i+1, g, v);
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<vector<char> > v(10, vector<char>(3));
    v[0].resize(1);
    v[1].resize(1);
    v[7].resize(4);
    v[9].resize(4);
    
    v[0][0] = '0';
    v[1][0] = '1';
    
    v[2][0] = 'a';
    v[2][1] = 'b';
    v[2][2] = 'c';
    
    v[3][0] = 'd';
    v[3][1] = 'e';
    v[3][2] = 'f';
    
    v[4][0] = 'g';
    v[4][1] = 'h';
    v[4][2] = 'i';
    
    v[5][0] = 'j';
    v[5][1] = 'k';
    v[5][2] = 'l';
    
    v[6][0] = 'm';
    v[6][1] = 'n';
    v[6][2] = 'o';
    
    v[7][0] = 'p';
    v[7][1] = 'q';
    v[7][2] = 'r';
    v[7][3] = 's';
    
    v[8][0] = 't';
    v[8][1] = 'u';
    v[8][2] = 'v';
    
    v[9][0] = 'w';
    v[9][1] = 'x';
    v[9][2] = 'y';
    v[9][3] = 'z';

    ans.clear();
    func(A, 0, "", v);
    sort(ans.begin(), ans.end());
    return ans;
}
