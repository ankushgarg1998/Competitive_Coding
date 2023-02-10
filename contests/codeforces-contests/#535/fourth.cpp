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
    int n, count = 0;
    cin>>n;
    string s;
    cin>>s;
    loop(i, 1, n-1) {
        if(s[i] == s[i-1]) {
            ++count;
            if(s[i] == 'R') {
                if(s[i+1] == 'R')
                    s[i] = 'G';
                else {
                    if(s[i+1] == 'G')
                        s[i] = 'B';
                    else
                        s[i] = 'G';
                }
            } else if(s[i] == 'G') {
                if(s[i+1] == 'G')
                    s[i] = 'R';
                else {
                    if(s[i+1] == 'R')
                        s[i] = 'B';
                    else
                        s[i] = 'R';
                }
            } else {
                if(s[i+1] == 'B')
                    s[i] = 'G';
                else {
                    if(s[i+1] == 'G')
                        s[i] = 'R';
                    else
                        s[i] = 'G';
                }
            }
        }
    }
    if(n > 1) {
        if(s[n-1] == s[n-2]) {
            ++count;
            if(s[n-2] == 'R')
                s[n-1] = 'G';
            else
                s[n-1] = 'R';
        }
    }
    cout<<count<<"\n"<<s<<"\n";
    return 0;
}