#include <iostream>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

bool first(string s) {
    loop(i, 0, s.size()) {
        if(i%2 == 0) {
            if(s[i] == '1')
                return false;
        } else {
            if(s[i] == '0')
                return false;
        }
    }
    return true;
}

bool second(string s) {
    loop(i, 0, s.size()) {
        if(i%2 == 0) {
            if(s[i] == '0')
                return false;
        } else {
            if(s[i] == '1')
                return false;
        }
    }
    return true;
}


int main() {
    test {
        int k;
        string s;
        bool flag = true;
        cin>>k;
        cin>>s;
        if(s.size() == 1) {
            if(s[0] == '?')
                cout<<"0\n";
            else if(s[0]-'0' >= k)
                cout<<"NO\n";
            else
                cout<<s<<"\n";
            continue;
        }
        if(k == 2) {
            if(s.size()%2 == 0) {
                int x = s.size()/2;
                if(first(s)) {
                    while(x--)
                        cout<<"01";
                } else if(second(s)) {
                    while(x--)
                        cout<<"10";
                } else {
                    cout<<"NO";
                }
            } else {
                cout<<"NO";
            }
            cout<<"\n";
            continue;
        }
        loop(i, 0, s.size()) {
            int next = (i+1)%s.size();
            int prev = (i == 0? s.size()-1: i-1);
            // cout<<next<<" "<<prev<<"\n";
            if(s[i] == s[next] && s[i] != '?') {
                flag = false;
                cout<<"NO\n";
                break;
            } else if(s[i] == '?') {
                int x = 0;
                while((x == s[prev]-'0' || x == s[next]-'0') && x<k)
                    ++x;
                if(x == k) {
                    flag = false;
                    cout<<"NO\n";
                    break;
                }
                s[i] = to_string(x)[0];
            }
            if(s[i]-'0' >= k) {
                flag = false;
                cout<<"NO\n";
                break;
            }
        }
        if(flag)
            cout<<s<<"\n";
    }
    return 0;
}
