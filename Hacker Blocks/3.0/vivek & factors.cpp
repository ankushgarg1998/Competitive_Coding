#include<iostream>
#define val 110000
using namespace std;

int main() {
    long int a[val]={0}, i, j, t, x, ans;
    for(i=1; i<val; i++)
        {
        for(j=i; j<val; j+=i)
            a[j] += i;
        }
    // for(i=0; i<20; i++)
    //     cout<<a[i]<<" ";
    do
        {
        cin>>x;
        if(x == 0)
            break;
        ans = -1;
        for(i=1; i<val; i++)
            {
            if(a[i] == x)
                {
                ans = i;
                break;
                }
            }
        cout<<ans<<"\n";
        }while(1);
	return 0;
}
