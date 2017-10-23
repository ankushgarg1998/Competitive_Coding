#include<iostream>
using namespace std;
long int ans(long int a, long int b)
    {
    if(a%b == 0)
        return b;
    else
        return ans(b, a%b);
    }

int main() {
    long int a, b;
    cin>>a>>b;
    if(a==b)
        cout<<a;
    else if(a>b)
        cout<<ans(a, b);
    else
        cout<<ans(b, a);
	return 0;
}
