#include <iostream>
#include<vector>
#include<algorithm>
#define li long int
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    int t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<li> v(n);
        li tot = 0, sum1=0, sum2 = 0;
        loop(i, 0, n) {
            cin>>v[i];
            tot += v[i];
        }

        sort(v.begin(), v.end());
        
        loop(i, 0, k)
            sum1 += v[i];

        loop(i, n-k, n)
            sum2 += v[i];

        cout<<max(max(sum1, tot-sum1) - min(sum1, tot-sum1), max(sum2, tot-sum2) - min(sum2, tot-sum2))<<"\n";
    }
    return 0;
}