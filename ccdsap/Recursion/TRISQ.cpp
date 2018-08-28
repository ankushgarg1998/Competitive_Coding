#include<iostream>
#define lli long long int
using namespace std;

lli rec(lli b) {
    if(b<4)
        return 0;
    if(b<6)
        return 1;
    return (2*((b-2)/2)-1)+rec(b-4);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        lli n;
        cin>>n;
        cout<<rec(n)<<"\n";
    }
    return 0;
}