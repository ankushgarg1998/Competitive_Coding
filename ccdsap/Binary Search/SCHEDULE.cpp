#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

bool possible(string s, li ans, li flips) {
    char curr = s[0];
    li count = 1;
    loop(i, 1, s.size()) {
        if(s[i] == curr)
            ++count;
        else {
            flips -= (count/(ans+1));
            curr = s[i];
            count = 1;
        }
    }
    flips -= (count/(ans+1));
    if(flips < 0)
        return false;
    return true;
}

int main() {
    test {
        li n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        string st = "01", s1="", s2="";
        int a=0, b=1;
        loop(i, 0, n) {
            s1 += st[(a++)%2];
            s2 += st[(b++)%2];
        }
        li k1=0, k2=0;
        loop(i, 0, n) {
            if(s[i] != s1[i])
                ++k1;
            if(s[i] != s2[i])
                ++k2;
        }
        if(min(k1, k2) <= k) {
            cout<<"1\n";
            continue;
        }
        
        li f=2, l=n, ans=n;
        while(f<=l) {
            li m = (f+l)/2;
            if(possible(s, m, k)) {
                ans = m;
                l = m-1;
            } else
                f = m+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}