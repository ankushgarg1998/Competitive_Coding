#include<iostream>
#include<vector>
using namespace std;

void update(vector<long int> &BIT, int i, int inc, int N) {
    while(i<=N) {
        BIT[i] += inc;
        i += (i & (-i));
    }
}

int query(vector<long int> &BIT, int i) {
    int sum = 0;
    while(i>0) {
        sum += BIT[i];
        i -= (i & (-i));
    }
    return sum;
}

int main() {
    long int t, n, x;
    cin>>t;
    while(t--) {
        long int a[200001], maxi=0;
        vector<long int> tree(10000001, 0);
        cin>>n;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
            maxi = max(a[i], maxi);
        }
        long long int ans = 0;
        for(int i=n; i>0; i--) {
            ans += query(tree, a[i]-1);
            update(tree, a[i], 1, maxi);
        // for(int i=0; i<=10; i++)
        //     cout<<tree[i]<<" ";
        // cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}