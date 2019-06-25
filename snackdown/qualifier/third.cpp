#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
using namespace std;

int main() {
    test {
        li n;
        cin>>n;
        vector<li> a(n, 0);
        for(li i=0; i<n; i++)
            cin>>a[i];
        li ptt = a[0], j = 1, day=0;
        while(j < n) {
            li new_ptt = ptt;
            for(li i=j; i<(j+ptt) && i<n; i++) {
                new_ptt += a[i];
            }
            j += ptt;
            ptt = new_ptt;
            ++day;
        }
        cout<<day<<"\n";
    }
    return 0;   
}