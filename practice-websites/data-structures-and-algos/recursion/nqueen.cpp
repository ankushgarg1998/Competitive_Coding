#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int n;

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
        loop(i, 0, n) {
            loop(j, 0, n)
                cout<<v[i][j];
            cout<<"\n";
        }
        cout<<"\n";
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

int main() {
    cin>>n;
    vector<vector<char> > v(n, vector<char>(n, '.'));
    rec(0, v);
    return 0;
}