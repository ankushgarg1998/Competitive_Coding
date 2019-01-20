#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    test {
        int n;
        cin>>n;
        map<li, int> m;
        li x;
        bool ans = true;
        while(n--) {
            cin>>x;
            ++m[x];
            if(m[x] >= 2)
                ans = false;
        }
        if(ans)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}