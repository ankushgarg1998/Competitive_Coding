#include <iostream>
#include <queue>
#include <set>
#include <map>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    test {
        int n, m;
        cin>>n>>m;
        int a[m][2];
        loop(i, 0, m) 
            cin>>a[i][0];

        loop(i, 0, m) {
            int j = i+1;
            for(; j<m; j++) {
                if(a[i][0] == a[j][0]) {
                    a[i][1] = j;
                    break;
                }
            }
            if(j == m)
                a[i][1] = m;
        }
        set<pair<int, int> > pq;
        map<int, int> mappy;
        int ans = 0;
        loop(i, 0, m) {
            if(mappy[a[i][0]]) {
                for(auto q: pq) {
                    if(q.second == a[i][0]) {
                        pq.erase(q);
                        pq.insert(make_pair(a[i][1], a[i][0]));
                        break;
                    }
                }
            }
            else if(pq.size() < n) {
                pq.insert(make_pair(a[i][1], a[i][0]));
                mappy[a[i][0]] = 1;
                ++ans;
            }
            else {
                ++ans;
                auto w = --pq.end();
                mappy[(*w).second] = 0;
                pq.erase(w);
                pq.insert(make_pair(a[i][1], a[i][0]));
                mappy[a[i][0]] = 1;
            }
        }
    cout<<ans<<"\n";
    }
    return 0;
}