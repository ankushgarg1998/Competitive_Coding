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

long double h, s;

long double area(long double x) {
    return (0.5*x*sqrt((h*h) - (x*x)));
}

int main() {
    test {
        cin>>h>>s;
        bool solved = false;
        long double first = 0.0000000000001, last = h;
        while(first<=last) {
            long double mid = (first+last)/2.000000;
            long double ar = area(mid);
            // cout<<fixed<<setprecision(7)<<first<<"-"<<mid<<"-"<<last<<" - "<<ar<<"\n";
            if(abs(s - ar) < 0.0000000001) {
                long double secno = sqrt((h*h) - (mid*mid));
                cout<<fixed<<setprecision(7)<<min(mid, secno)<<" "<<max(mid, secno)<<" "<<h<<"\n";
                solved = true;
                break;
            } else if(ar < s)
                first = mid + 0.0000000000001;
            else
                last = mid - 0.0000000000001;
        }
        if(!solved)
            cout<<"-1\n";
    }
    return 0;
}