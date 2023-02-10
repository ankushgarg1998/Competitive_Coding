#include <iostream>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    while(t--)
        {
        long long int a, b, x, ans=0;
        cin>>a>>b;
        while(a!=0 && b!=0)
          {
          x = (a%10)+(b%10);
          ans = (10*ans)+ (x%10);
          a /= 10; b /= 10;
          }
        cout<<ans<<"\n";
        }
    return 0;
    }
