#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin>>x;
    cout<<x<<"\n";
    cin>>x;
    cout<<x<<"\n";
    int c = -1;
    while(cin>>x) {
        if(++c%3 != 0)
            cout<<x<<" ";
        if(c%3 == 2)
            cout<<"\n";
    }
}
