#include <iostream>
// #include <queue>
#include <deque>
// #include <stack>
#include <algorithm>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int n, p;

bool rec(int *a, deque<int> *vq, int xi) {
    if(xi == p)
        return true;
    loop(i, 0, n) {
        if(vq[i].front() == a[xi]) {
            vq[i].pop_front();
            if(rec(a, vq, xi+1))
                return true;
            vq[i].push_front(a[xi]);
        }
    }
    return false;
}

int main() {
    test {
        int l, x;
        p=0;
        cin>>n;
        // vector<queue<int> > vq(n);
        deque<int> vq[n];
        loop(i, 0, n) {
            cin>>l;
            p += l;
            loop(j, 0, l) {
                cin>>x;
                vq[i].push_back(x);
            }
        }
        // vector<int> v(p);
        int v[p];
        loop(i, 0, p)
            cin>>v[i];

        reverse(v, v+p);
        if(rec(v, vq, 0))
            cout<<"Yes";
        else
            cout<<"No";
        cout<<"\n";
    }
    return 0;
}
