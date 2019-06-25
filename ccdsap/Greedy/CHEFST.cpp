#include <iostream>
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    test {
        lli n1, n2, m;
        cin>>n1>>n2>>m;
        lli mins = min(n1, n2);
        lli maxt = ((m*(m+1))/2);
        if(mins <= maxt) {
            cout<<max(n1, n2) - mins<<"\n";
        } else {
            cout<<(mins-maxt) + (max(n1, n2) - maxt)<<"\n";
        }
    }
    return 0;
}
