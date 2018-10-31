#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int a[100], n;
int main() {
    test {
        cin>>n;
        bool allEqual = true;
        loop(i, 0, n) {
            cin>>a[i];
            if(a[i] != 47)
                allEqual = false;
        }

        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=i;
        }
        for(int i=0;i<n;i++){
            int minMinVal = 100;
            for(int j=i+1;j<n;j++){
                if(__gcd(a[i],a[j])==1){
                    int minVal = min(dp[i],dp[j]);
                    minMinVal = min(minMinVal, minVal);
                }
            }
            for(int j=i+1;j<n;j++){
                if(__gcd(a[i],a[j])==1){
                    dp[i]=minMinVal;
                    dp[j]=minMinVal;
                }
            }
        }
        bool flag=0;
        for(int i=1;i<n;i++){
            if(dp[i]!=dp[0]){
                flag=1;
                break;
            }
        }
        int changes = 0;
        // if(cc != 1) {
        if(flag == 1) {
            changes = 1;
            a[0] = (allEqual? 2: 47);
        }
        cout<<changes<<"\n";
        loop(i, 0, n)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}