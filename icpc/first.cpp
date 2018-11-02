#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main()
    {
    test {
        string s;
        cin>>s;
        int a[60] = {0};
        int l = s.size();
        loop(i, 0, l) {
            if(s[i] != '.') {
                int x = s[i] - '0';
                loop(j, max(0, i-x), min(i+x+1, l)) {
                    ++a[j];
                }
            }
        }

        string ans = "safe";
        loop(i, 0, l) {
            if(a[i] > 1) {
                ans = "unsafe";
                break;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
    }