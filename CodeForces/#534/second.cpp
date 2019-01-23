#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    string s;
    cin>>s;
    li si = s.size();
    stack<char> st;
    li count = 0;
    st.push(s[0]);
    loop(i, 1, si) {
        if(st.empty())
            st.push(s[i]);
        else {
            if(st.top() == s[i]) {
                ++count;
                st.pop();
            }
            else
                st.push(s[i]);
        }
    }
    if(count % 2 == 0)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}