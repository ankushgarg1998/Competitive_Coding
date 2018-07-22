#include<iostream>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

string s;

bool contains(string a, string b) {
    int i=0, j=0, sa = a.length()-1, sb = b.length()-1;
    step:
    if(i>sa)
        return true;
    if(j>sb)
        return false;
    if(a[i] == b[j]) {
        ++i; ++j;
        goto step;
    }
    if(i == 0) {
        ++j;
        goto step;
    }
    i=0;
    goto step;
}

void print(int test, string ans) {
    cout<<"Case #"<<test<<": "<<(ans == "\0" ? "Impossible": ans)<<"\n";
}

int main() {
    int t;
    cin>>t;
    
    loop(test, 1, t+1) {
        cin>>s;
        if(s.length() < 3)
            print(test, "\0");
        else {
            int len = s.length();
            string ans = "";
            ans += s[0];
            bool found = false;
            loop(i, 1, len) {
                if(s[i] == s[0]) {
                    ans += s;
                    found = true;
                    break;
                }
                ans += s[i];
            }
            if(found && !contains(s, ans))
                print(test, ans);
            else
                print(test, "\0");
        }
    }
    return 0;
}