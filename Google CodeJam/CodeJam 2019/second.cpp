#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    testing {
        li n;
        cin>>n;
        string s, s1="";
        cin>>s;
        loop(i, 0, s.size()) {
            s1 += (s[i] == 'S'? "E":"S");
        }
        cout<<"Case #"<<t<<": "<<s1<<"\n";
    }
    return 0;
}