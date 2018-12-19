#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    long int arr[100][100], v=7, e=10, a, b, c, s=1, d[100];

    loop(i, 0, 50) {
        d[i] = INT_MAX;
        loop(j, 0, 50)
            arr[i][j] = INT_MAX;
    }
    loop(i, 0, e) {
        cin>>a>>b>>c;
        arr[a][b] = c;
    }
    d[1] = 0;
    loop(i, 0, v-1) {
        loop(i, 1, v+1) {
            loop(j, 1, v+1) {
                if(arr[i][j] != INT_MAX && d[i] != INT_MAX) {
                    d[j] = min(d[j], d[i] + arr[i][j]);
                }
            }
        }
    }

    loop(i, 1, v+1) {
        cout<<i<<"="<<d[i]<<"\t";
    }
    return 0;
}