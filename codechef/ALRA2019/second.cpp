#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    test {
        int n, m;
        string s;
        cin>>n>>m;
        cin>>s;
        map<char, set<char> > mp;
        vector<string> good, bad;
        while(m--) {
            string temp1, temp2;
            cin>>temp1>>temp2;
            mp[temp1[0]].insert(temp2[0]);
        }

        while(true) {
            vector<string> good;
            for(auto x: mp) {
                string str = "";
                char c = x.first;
                for(char ch: x.second) {
                    if(mp.find(ch) != mp.end()) {
                        for(char ch2: mp[ch]) {
                            if(x.second.find(ch2) == x.second.end() && ch2 != c)
                                str += ch2;
                        }
                    }
                }

                if(str != "") {
                    // cout<<"in\n";
                    string str2 = c + str;
                    // cout<<str2<<"-\n";
                    good.push_back(str2);
                }
            }

            if(good.size() == 0)
                break;
            else {
                // cout<<"once\n";
                for(string str: good) {
                    char c = str[0];
                    loop(i, 1, str.size()) {
                        mp[c].insert(str[i]);
                    }
                }
            }
        }

        // for(auto x: mp) {
        //     cout<<x.first<<"->";
        //     for(auto ch: x.second)
        //         cout<<ch<<" ";
        //     cout<<"\n";
        // }

        loop(i, 0, s.size()) {
            if(mp.find(s[i]) != mp.end()) {
                if(*(mp[s[i]].begin()) < s[i])
                    s[i] = *(mp[s[i]].begin());
            }
        }

        cout<<s<<"\n";
    }
    return 0;
}