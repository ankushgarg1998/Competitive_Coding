#include <iostream>
#include<math.h>
using namespace std;
int main() {
    int t;
    long long int N, K, ans;
    cin>>t;
    while(t--)
        {
        cin>>N>>K;
        ans = pow(N, 1.0/K);
        cout<<ans<<"\n";
        }
    return 0;
}
