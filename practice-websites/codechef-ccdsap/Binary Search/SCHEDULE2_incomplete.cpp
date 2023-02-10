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

int main() {
    test {
        li n, k, kk;
        cin>>n>>k;
        kk = k;
        string s;
        cin>>s;
        multiset<li, greater<li> > ms;
        char curr = s[0];
        li count = 1;
        loop(i, 1, n) {
            if(s[i] != curr) {
                ms.insert(count);
                curr = s[i];
                count = 1;
            } else
                ++count;
        }
        ms.insert(count);
        
        while(k--) {
            li val = *(ms.begin());
            if(val <= 2) {
                break;
            }
            ms.erase(ms.begin());
            ms.insert(val/2);
            if(val % 2 == 0) {
                ms.insert((val/2)-1);
            } else {
                ms.insert(val/2);
            }
        }

        li val = *(ms.begin());
        if(val > 2) {
            cout<<val<<"\n";
        } else {
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
            if(min(k1, k2) <= kk)
                cout<<"1\n";
            else
                cout<<"2\n";
        }
    }
    return 0;
}