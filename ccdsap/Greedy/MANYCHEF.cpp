#include <iostream>
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    test {
        string s;
        cin>>s;
        int ans = 0;
        if(s.size() < 4) {
            goto alpha;
        }
        for(int i = s.size()-4; i>=0; i--) {
            if(s[i] == 'C' || s[i] == '?') {
                ++i;
                if(s[i] == 'H' || s[i] == '?') {
                    ++i;
                    if(s[i] == 'E' || s[i] == '?') {
                        ++i;
                        if(s[i] == 'F' || s[i] == '?') {
                            s[i] = 'F';
                            s[i-1] = 'E';
                            s[i-2] = 'H';
                            s[i-3] = 'C';
                            ++ans;
                            i -= 6;
                        } else
                            i -= 3;
                    } else
                        i -= 2;
                } else
                    --i;
            }
        }
        alpha:
        loop(i, 0, s.size()) {
            if(s[i] == '?')
                s[i] = 'A';
        }
        cout<<s<<"\n";
    }
    return 0;
}