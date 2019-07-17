int N, K, P;

int MOD = 1000000007;

long long int lol(int x, int y, vector<vector<long long int> > &v, vector<int> &A, vector<int> &B) {
    if(x == N-1)
        return 0;
    if(v[x][y] != -1)
        return v[x][y];
        
    long long int ans = 10000000000000000;
    if(y == 0) {
        for(int i=1; x+i<N && i<=K; i++) {
        ans = min(ans, A[x+i] + lol(x+i, 0, v, A, B));
        ans = min(ans, P + B[x+i] + lol(x+i, 1, v, A, B));
        }
    } else {
        for(int i=1; x+i<N && i<=K; i++) {
        ans = min(ans, P + A[x+i] + lol(x+i, 0, v, A, B));
        ans = min(ans, B[x+i] + lol(x+i, 1, v, A, B));
        }
    }
    return v[x][y] = ans;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C, int D) {
    N = A.size();
    vector<vector<long long int> > v(N, vector<long long int>(2, -1));
    K = C;
    P = D;
    return min(A[0] + lol(0, 0, v, A, B), B[0] + lol(0, 1, v, A, B))%MOD;
}

