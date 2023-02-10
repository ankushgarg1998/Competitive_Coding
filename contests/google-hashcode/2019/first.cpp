#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int n, counth, countv;
    char ch;
    int tags, x=-1;
    string s;
    vector<pair<int, int> > v;
    cin>>n;
    loop(i, 0, n) {
        cin>>ch;
        cin>>tags;
        while(tags--)
            cin>>s;
        if(ch == 'H') {
            ++counth;
            v.push_back(make_pair(i, -1));
        }
        else {
            ++countv;
            if(x == -1)
                x = i;
            else {
                v.push_back(make_pair(x, i));
                x = -1;
            }
        }
    }
    // random_shuffle(v.begin(), v.end();
    unsigned seed = 3;
    shuffle(v.begin(), v.end(), default_random_engine(seed));
    cout<<v.size()<<"\n";
    for(auto p: v) {
        cout<<p.first;
        if(p.second != -1)
            cout<<" "<<p.second;
        cout<<"\n";
    }
    return 0;
}