#include <iostream>
#include <algorithm>
#define lli long long int
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    lli n, d;
    cin>>n>>d;
    // vector<lli> v(n);
    lli v[n], pairs = 0;
    loop(i, 0, n)
        cin>>v[i];

    sort(v, v+n);

    loop(i, 0, n-1) {
        if(v[i+1] - v[i] <= d) {
            ++i;
            ++pairs;
        }
    }

    cout<<pairs<<"\n";
    return 0;
}
