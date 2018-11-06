#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int n;
string s;

int count(char ch, int i) {
    loop(j, i, n) {
        if(s[j] != ch)
            return (j-i);
    }
    return (n-i);
}

int main() {
    test {
        cin>>n;
        cin>>s;
        int i=0;
        while(s[i] == '#') {
            ++i;
        }

        li ans = 0;
        int predots = count('.', i);
        int j = i + predots;

        while(true) {
            if(j >= n)
                break;
            int hashes = count('#', j);
            j += hashes;
            if(j >= n) {
                ans = -1;
                break;
            }
            int postdots = count('.', j);
            if(postdots < hashes) {
                ans = -1;
                break;
            }

            li m1 = ((hashes-1)*hashes)/2;
            li m2 = (hashes*predots) + (m1);

            ans += (m1+m2);

            j += postdots;
            predots += postdots;
        }
        cout<<ans<<"\n";
    }
    return 0;
}