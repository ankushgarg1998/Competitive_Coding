#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

bool allone(int d[100][2], int v) {
    loop(i, 1, v+1) {
        if(d[i][1] != 1)
            return false;
    }
    return true;
}

int extractmin(int d[100][2], int v) {
    int ind = -1, val = INT_MAX;
    loop(i, 1, v+1) {
        if(d[i][1] == 0 && d[i][0] < val) {
            ind = i;
            val = d[i][0];
        }
    }
    d[ind][1] = 1;
    return ind;
}

int main() {
    int arr[100][100], v=6, e=11, a, b, c, s=1, d[100][2];

    loop(i, 0, 50) {
        d[i][0] = INT_MAX;
        d[i][1] = 0;
        loop(j, 0, 50)
            arr[i][j] = INT_MAX;
    }
    loop(i, 0, e) {
        cin>>a>>b>>c;
        arr[a][b] = c;
    }
    d[1][0] = 0;
    while(!allone(d, v)) {
        int u = extractmin(d, v);
        if(u == -1)
            break;
        loop(i, 1, v+1) {
            if(arr[u][i] != INT_MAX) {
                d[i][0] = min(d[i][0], d[u][0] + arr[u][i]);
            }
        }
    }

    loop(i, 1, v+1) {
        cout<<i<<"="<<d[i][0]<<"\t";
    }
    return 0;
}