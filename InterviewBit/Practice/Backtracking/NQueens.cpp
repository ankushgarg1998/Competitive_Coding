#define loop(i, a, b) for(int i=a; i<b; i++)

int n, anscount;
vector<vector<string> > ans;

bool issafe(vector<vector<char> > &v, int x, int y) {
    // cout<<x<<" "<<y<<"-\n";
    loop(i, 0, n) {
        if(v[x][i] == 'Q') return false;
    }
    loop(i, 0, n) {
        if(v[i][y] == 'Q') return false;
    }
    for(int i=x, j=y; i>=0 && j>=0;) {
        if(v[i][j] == 'Q') return false;
        --i; --j;
    }
    for(int i=x, j=y; i>=0 && j<n;) {
        if(v[i][j] == 'Q') return false;
        --i; ++j;
    }
    for(int i=x, j=y; i<n && j>=0;) {
        if(v[i][j] == 'Q') return false;
        ++i; --j;
    }
    for(int i=x, j=y; i<n && j<n;) {
        if(v[i][j] == 'Q') return false;
        ++i; ++j;
    }

    return true;
}


void rec(int r, vector<vector<char> > &v) {
    if(r == n) {
        ans.push_back( vector<string>() );
        loop(i, 0, n) {
            string str = "";
            loop(j, 0, n) {
                str += v[i][j];
            }
            ans[anscount].push_back(str);
        }
        ++anscount;
        return;
    }
    loop(i, 0, n) {
        if(issafe(v, r, i)) {
            v[r][i] = 'Q';
            rec(r+1, v);
            v[r][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ans.clear();
    anscount=0;
    n = A;
    vector<vector<char> > v(n, vector<char>(n, '.'));
    rec(0, v);
    return ans;
}
