#include<iostream>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int t, n, a[100];
    cin>>t;
    loop(test, 1, t+1) {
        cin>>n;
        loop(i, 0, n+1)
            cin>>a[i];
        cout<<"Case #"<<test<<": "<< (n%2 == 0 ? "0": "1\n0.0")<<"\n";
    }
    return 0;
}