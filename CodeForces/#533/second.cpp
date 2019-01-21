#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    char prev = s[0];
    int ct = 1;
    int alpha[26] = {0};
    loop(i, 1, s.size()) {
        if(ct == k) {
            ++alpha[prev - 'a'];
            ct = 0;
        }
        if(s[i] == prev) {
            ++ct;
        } else {
            prev = s[i];
            ct = 1;
        }
    }
    if(ct == k)
        ++alpha[prev - 'a'];

    int maxi = 0;
    loop(i, 0, 26) {
        maxi = max(maxi, alpha[i]);
    }
    cout<<maxi<<"\n";
    return 0;
}