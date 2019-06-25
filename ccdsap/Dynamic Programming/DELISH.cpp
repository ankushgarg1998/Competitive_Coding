#include<iostream>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>=b; i--)
using namespace std;

int main() {
    test {
        int n;
        cin>>n;
        lli a[n];

        lli hardRightMax[n], hardRightMin[n], hardLeftMax[n], softLeftMax[n], hardLeftMin[n], softLeftMin[n];
        loop(i, 0, n)
            cin>>a[i];

        hardRightMax[n-1] = a[n-1];
        loopr(i, n-2, 0) {
            hardRightMax[i] = max(a[i], a[i] + hardRightMax[i+1]);
        }

        hardRightMin[n-1] = a[n-1];
        loopr(i, n-2, 0) {
            hardRightMin[i] = min(a[i], a[i] + hardRightMin[i+1]);
        }

        hardLeftMax[0] = a[0];
        loop(i, 1, n) {
            hardLeftMax[i] = max(a[i], a[i] + hardLeftMax[i-1]);
        }

        softLeftMax[0] = a[0];
        loop(i, 1, n) {
            softLeftMax[i] = max(softLeftMax[i-1], hardLeftMax[i]);
        }

        hardLeftMin[0] = a[0];
        loop(i, 1, n) {
            hardLeftMin[i] = min(a[i], a[i] + hardLeftMin[i-1]);
        }

        softLeftMin[0] = a[0];
        loop(i, 1, n) {
            softLeftMin[i] = min(softLeftMin[i-1], hardLeftMin[i]);
        }

        lli ans = 0;
        loop(i, 0, n-1) {
            ans = max(ans, max(abs(softLeftMax[i] - hardRightMin[i+1]), abs(softLeftMin[i] - hardRightMax[i+1])));
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}