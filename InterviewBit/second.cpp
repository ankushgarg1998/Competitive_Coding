#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

int main() {
    long long int n = 702;
    string str = "";
    cin>>n;
    long long int x = 0, dig = 0;
    while(x < n) {
        ++dig;
        x += pow(26, dig);
    }
    long long int kitnwa_num = n-(x-pow(26, dig))-1;
    // cout<<dig<<"\n"<<kitnwa_num<<"\n";
    for(long long int i=1; i<=dig; i++) {
        long long int ts = pow(26, dig-i);
        long long int ch = kitnwa_num/ts;
        kitnwa_num = kitnwa_num%ts;
        str += (char)(ch + 97);
    }
    if(dig >= 2) {
        for(long long int i=dig-2; i>=0; i--) {
            str += str[i];
        }
    }
    cout<<str;
    return 0;
}