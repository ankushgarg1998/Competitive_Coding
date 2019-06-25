#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long long
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    test {
        int n, j=0, ones=0;
        cin>>n;
        li a[n], x;
        loop(i, 0, n) {
            cin>>x;
            if(x == 1)
                ++ones;
            else
                a[j++] = x;
        }
        sort(a, a+j, greater<li>());
        if(a[0] == 3) {
            int k=0;
            while(k<j && a[k]==3)
                ++k;
            if(k<j && a[k]==2)
                swap(a[0], a[k]);
        }
        loop(i, 0, ones)
            cout<<"1 ";
        loop(i, 0, j)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}