#include <iostream>
#define test int t; cin>>t; while(t--)
using namespace std;

int fib(int n, int m) {
    if (n == 1 || n == 2) 
        return 2;

    int ans = 0, first=2, second=2;
    for(int i=3; i<=n; i++) {
        ans = (first+second);
        ans %= m;
        first = second;
        second = ans;
    }
    return ans;
}

int main() {
    test {
        int n, m;
        cin>>n>>m;
        cout<<(2*fib(n, m))%m<<"\n";
    }
    return 0;
}