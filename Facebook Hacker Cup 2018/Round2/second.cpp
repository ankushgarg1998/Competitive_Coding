#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define tes int t; cin>>t; for(int test=1; test<=t; test++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

lli earning;

// lli sell(lli candy, lli parent, vector<lli> &pending, vector<lli> &P) {
//     if(pending[parent]) {
//         earning += candy;
//         --pending[parent];
//         return parent;
//     } else if (parent == 0) {
//         return 0;
//     } else {
//         P[parent] = sell(candy, P[parent], pending, P);
//         return P[parent];
//     }
// }

void sell(lli candy, lli parent, vector<lli> &pending, vector<lli> &P) {
    if(pending[parent]) {
        earning += candy;
        --pending[parent];
        return;
    } else if (parent == 0) {
        return;
    } else {
        sell(candy, P[parent], pending, P);
    }
}

int main()
    {
    tes {
        lli n, m, a, b;
        cin>>n>>m>>a>>b;
        vector<lli> P(n, 0);
        vector<lli> pending(n, 0);
        loop(i, 1, n)
            cin>>P[i];
        lli jugaad;
        loop(i, 0, m) {
            jugaad = (a*i + b) % n;
            pending[jugaad] += 1;
        }
        
        earning = 0;
        // lli x;
        loopr(i, n-1, 0) {
            sell(i, i, pending, P);
        }
        cout<<"Case #"<<test<<": "<<earning<<"\n";
    }
    return 0;
    }