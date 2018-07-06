#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main()
    {
    int n, pre[10]={0}, ne[10]={0};
    string s;
    cin>>n;
    loop(i, 0, n) {
        cin>>s;
        if(s == "M") {
            ++pre[0];
        } else if(s == "S") {
            ++pre[1];
        } else if(s == "L") {
            ++pre[2];
        } else if(s == "XS") {
            ++pre[3];
        } else if(s == "XL") {
            ++pre[4];
        } else if(s == "XXS") {
            ++pre[5];
        } else if(s == "XXL") {
            ++pre[6];
        } else if(s == "XXXS") {
            ++pre[7];
        } else if(s == "XXXL") {
            ++pre[8];
        }
    }
    loop(i, 0, n) {
        cin>>s;
        if(s == "M") {
            ++ne[0];
        } else if(s == "S") {
            ++ne[1];
        } else if(s == "L") {
            ++ne[2];
        } else if(s == "XS") {
            ++ne[3];
        } else if(s == "XL") {
            ++ne[4];
        } else if(s == "XXS") {
            ++ne[5];
        } else if(s == "XXL") {
            ++ne[6];
        } else if(s == "XXXS") {
            ++ne[7];
        } else if(s == "XXXL") {
            ++ne[8];
        }
    }
    int ans = 0;
    loop(i, 0, 9) {
        ans += ne[i];
        ans -= min(pre[i], ne[i]);
    }
    cout<<ans<<"\n";
    return 0;
    }