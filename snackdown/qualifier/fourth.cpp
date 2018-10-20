#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
using namespace std;

int main() {
    test {
        li n;
        cin>>n;
        vector<li> a(n), b(n);
        loop(i, 0, n)
            cin>>a[i];
        loop(i, 0, n)
            cin>>b[i];

        bool ans = true;
        if(n == 1) {
            if(a[0] != b[0])
                ans = false;
        } else if(n == 2) {
            if(a[0] != b[0] || a[1] != b[1])
                ans = false;
        } else {
            loop(i, 0, n-2) {
                if(a[i] > b[i]) {
                    ans = false;
                    break;
                } else if(a[i] < b[i]) {
                    int x = b[i] - a[i];
                    a[i] += x;
                    a[i+1] += (2*x);
                    a[i+2] += (3*x);
                }
            }
            if(ans) {
                if(a[n-2] != b[n-2] || a[n-1] != b[n-1])
                    ans = false;
            }
        }

        if(ans)
            cout<<"TAK";
        else
            cout<<"NIE";
        cout<<"\n";
    }
    return 0;   
}