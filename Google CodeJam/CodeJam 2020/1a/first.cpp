#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
lli power(lli a, lli p) { lli ans=1; while(p>0) { if(p&1) ans*=a; p>>=1; a*=a; } return ans; }
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

string commonPrefix(string prefix, string str) {
    for(int i=0; i<prefix.size() && i<str.size(); i++) {
        if(prefix[i] != str[i])
            return "-1";
    }
    return (prefix.size() > str.size()? prefix: str);
}

string commonSuffix(string suffix, string str) {
    for(int i=0; i<suffix.size() && i<str.size(); i++) {
        if(suffix[suffix.size()-(i+1)] != str[str.size()-(i+1)])
            return "-1";
    }
    return (suffix.size() > str.size()? suffix: str);
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    testing {
        int n;
        cin>>n;
        string patterns[n];
        loop(i, 0, n)
            cin>>patterns[i];
        string prefix="", suffix="", temp="";
        vector<string> midStrings;
        string ans = "";

        loop(i, 0, n) {
            int prefixTill = patterns[i].find_first_of("*");
            int suffixTill = patterns[i].find_last_of("*");
            prefix = commonPrefix(prefix, patterns[i].substr(0, prefixTill));
            suffix = commonSuffix(suffix, patterns[i].substr(suffixTill+1, patterns[i].size()));

            if(prefix == "-1" || suffix == "-1") {
                ans = "*";
                break;
            }

            if(suffixTill != prefixTill) {
                string left = patterns[i].substr(prefixTill+1, suffixTill-prefixTill);
                if(left != "") {
                    string s = "";
                    loop(j, 0, left.size()) {
                        if(left[j] == '*') {
                            if(s != "")
                                midStrings.push_back(s);
                            s = "";
                        } else 
                            s += left[j];
                    }
                    if(s != "")
                        midStrings.push_back(s);
                }
            }

            // cout<<"\nPrefix: "<<prefix<<" Suffix: "<<suffix<<"\n";
            // for(string s: midStrings)
            //     cout<<s<<", ";
            // cout<<"\n";
        }

        if(ans != "*") {
            ans += prefix;
            for(string s: midStrings)
                ans += s;
            ans += suffix;
        }
        cout<<"Case #"<<t<<": "<<(ans == ""? "*": ans)<<"\n";
    }
    return 0;
}