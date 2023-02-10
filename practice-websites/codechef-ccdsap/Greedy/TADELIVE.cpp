#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first);
}

int main() {
        int n, x, y;
        cin>>n>>x>>y;
        int a[n], b[n];
        vector<pair<int, int> > c;
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n) {
            cin>>b[i];
            c.push_back(make_pair(b[i] - a[i], i));
        }
        sort(c.begin(), c.end(), compare);

        // for(auto f: c)
        //     cout<<f.first<<" "<<f.second<<"\n";

        lli ans = 0;
        int i=0;
        while(c[i].first <= 0 && x--) {
            ans += a[c[i].second];
            ++i;
        }
        int j = i;
        i = n-1;
        while(i>=j && y--)  {
            ans += b[c[i].second];
            --i;
        }
        while(i>=j && x--) {
            ans += a[c[i].second];
            --i;
        }

        cout<<ans<<"\n";
    return 0;
}