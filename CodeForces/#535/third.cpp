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
    int n;
    cin>>n;
    string s, si[6] = {"", "", ""};
    int del[6] = {0, 0, 0};
    cin>>s;
    string str="RGB", str2="RBG";
    loop(m, 0, 3) {
        int k = m;
        loop(i, 0, n) {
            si[m] += str[k];
            k = (k+1)%3;
        }
    }
    loop(m, 3, 6) {
        int k = m-3;
        loop(i, 0, n) {
            si[m] += str2[k];
            k = (k+1)%3;
        }
    }

    loop(m, 0, 6) {
        loop(i, 0, n) {
            if(si[m][i] != s[i])
                ++del[m];
        }
    }

    int mini = INT_MAX, c;
    loop(i, 0, 6) {
        if(del[i] < mini) {
            c = i;
            mini = del[i];
        }
    }
    cout<<mini<<"\n"<<si[c]<<"\n";
    return 0;
}