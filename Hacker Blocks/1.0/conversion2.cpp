#include <iostream>
#include<math.h>
#include<string>
using namespace std;
int main() {
    int sb, db, i=0;
    long int n, ans=0;
    char str[50] = {'0'};
    string s;
    cin>>sb>>db>>n;
    // if(sb == db)
    //     cout<<n;
    if(sb != 10)
        {
        while(n!=0)
            {
            ans += (n%10)*pow(sb, i);
            n /= 10;
            ++i;
            }
        n = ans;
        // cout<<ans<<"\n";
        }
    if (db == 10)
        cout<<n;
    else
        {
        i=0;
        while(n!=0)
            {
            str[i] = (n%db) + '0';
            ++i;
            n /= db;
            }
        for(--i;i>=0; i--)
            cout<<str[i];
        }
    return 0;
}
