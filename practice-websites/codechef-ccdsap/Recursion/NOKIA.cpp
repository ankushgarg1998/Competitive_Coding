#include<iostream>
using namespace std;

int rec(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 2;
    if(n&1)
        return n+rec(n/2)+rec((n+1)/2);
    else
        return n+(2*rec(n/2));
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, mini=0, maxi=0;
        cin>>n>>m;
        ++n;
        for(int i=2; i<=n; i++)
            maxi += i;
        mini = rec(n);
        // cout<<mini<<" "<<maxi<<"\n";
        if(m >= maxi)
            cout<<m-maxi;
        else if(m >= mini)
            cout<<0;
        else
            cout<<-1;
        cout<<"\n";
    }
    return 0;
}