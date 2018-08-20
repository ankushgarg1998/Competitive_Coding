#include<iostream>
#include<map>
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    test {
        string s;
        bool ans = true;
        map<char, int> hm;
        cin>>s;
        int siz = s.size();

        loop(i, 0, siz/2)
            ++hm[s[i]];
        loop(i, siz&1? (siz+1)/2: siz/2, siz)
            --hm[s[i]];

        for(auto x: hm) {
            if(x.second != 0)
                ans = false;
        }
        if(ans)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
    return 0;
}