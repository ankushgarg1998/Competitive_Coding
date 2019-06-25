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
    li n, M, a[100010], b[100010], c[100010], sumod[100010]={0}, sumev[100010]={0}, prev=0, sumodd=0, sumeve=0;
    cin>>n>>M;
    loop(i, 0, n) {
        cin>>a[i];
        b[i] = a[i] - prev;
        prev = a[i];
    }
    b[n] = M-prev;
    // loop(i, 0, n+1)
    //     cout<<b[i]<<" ";
    prev = 0;
    li maxci=0, imaxci=0;
    loop(i, 0, n+1) {
        if(i%2 == 0) {
            c[i] = prev + b[i];
            sumeve += b[i];
            sumev[i] = sumeve;
        } else {
            c[i] = prev - b[i];
            sumodd += b[i];
            sumod[i] = sumodd;
        }
        prev = c[i];
        if(c[i] >= maxci) {
            maxci = c[i];
            imaxci = i;
        }
    }
    // cout<<"\n";
    // loop(i, 0, n+1)
    //     cout<<c[i]<<" ";
    if(imaxci == n) {
        cout<<sumev[imaxci];
    } else if(imaxci == 0) {
        cout<<sumodd + c[0] - 1;
    } else {
        cout<<(sumev[imaxci]-1)+(sumodd-sumod[imaxci-1]);
    }
    return 0;
    }