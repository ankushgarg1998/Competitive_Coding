#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        long int n, u, l, r, val, q, index, adder=0;
        scanf("%ld%ld", &n, &u);
        vector<long int> v(n+1, 0);
        while(u--) {
            scanf("%ld%ld%ld", &l, &r, &val);
            v[l] += val;
            v[r+1] -= val;
        }
        scanf("%ld", &q);
        for(long int i=0; i<n; i++) {
            adder += v[i];
            v[i] = adder;
        }
        while(q--) {
            scanf("%ld", &index);
            printf("%ld\n", v[index]);
        }
    }
    return 0;
}