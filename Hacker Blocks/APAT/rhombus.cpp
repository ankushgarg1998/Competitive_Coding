#include <iostream>
using namespace std;
int main() {
    int n, i, j, k;
    cin>>n;
    for(i=1; i<=n; i++)
        {
        for(k=i; k<n; k++)
            cout<<"\t";
        for(j=i; j<(2*i); j++)
            cout<<j<<"\t";
        --j;
        for(--j; j>=i; j--)
            cout<<j<<"\t";
        cout<<"\n";
        }
    i-=2;
    for(; i>0; i--)
        {
        for(k=i; k<n; k++)
            cout<<"\t";
        for(j=i; j<(2*i); j++)
            cout<<j<<"\t";
        --j;
        for(--j; j>=i; j--)
            cout<<j<<"\t";
        cout<<"\n";
        }
}
