#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

void print(int i, vector<pair<int, int> > &v) {
    cout<<v[i].first;
    if(v[i].second != -1)
        cout<<" "<<v[i].second;
    cout<<"\n";
}

int main() {
    int n, tags, x = -1, lol=0;
    char ch;
    string s;
    cin>>n;
    vector<pair<int, int> > ans(n);
    vector<set<string> > v(n);
    vector<int> used(n, 0);
    vector<string> temp(100);
    loop(i, 0, n) {
        cin>>ch;
        cin>>tags;
        if(ch == 'H' || x == -1) {
            ++lol;
            while(tags--) {
                cin>>s;
                v[i].insert(s);
            }
            if(ch == 'V') {
                x = i;
                used[i] = 1;
                --lol;
            } else
                ans[i] = make_pair(i, -1);
        } else {
            while(tags--) {
                cin>>s;
                v[x].insert(s);
            }
            used[x] = 0; used[i] = 1;
            ans[x] = make_pair(x, i);
            x = -1;
        }
    }

    cout<<lol<<"\n";
    print(0, ans);
    used[0] = 1;
    int prev = 0;
    while(true) {
        int maxval = 0;
        int maxi = -1;
        loop(i, 1, n) {
            if(used[i] == 0) {
                int si = set_intersection(v[prev].begin(), v[prev].end(), v[i].begin(), v[i].end(), temp.begin()) - temp.begin();
                int val = min(si, (int)min(v[prev].size()-si, v[i].size()-si));
                if(val >= maxval) {
                    maxval = val;
                    maxi = i;
                }
            }
        }
        if(maxi == -1)
            break;
        used[maxi] = 1;
        prev = maxi;
        print(maxi, ans);
    }
    return 0;
}