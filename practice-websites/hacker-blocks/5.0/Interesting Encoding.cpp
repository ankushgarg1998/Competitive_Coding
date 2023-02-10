#include <iostream>
using namespace std;

bool chk(char a, char b)
    {
    int x = ((10 * (a - '0')) + (b - '0'));
    if(x <= 26)
        return true;
    else return false;
    }

int main() {
long int n, ans[5000], i, len;
    string a;
    cin>>n;
    while(n--)
        {
        cin>>a;
        len = a.size();
        if(len <= 1)
            {
            if(a[0] == '0')
              cout<<"0\n";
            else
              cout<<"1\n";
            continue;
            }

        ans[len-1] = 1;
        ans[len-2] = 1;
        if(chk(a[len-2], a[len-1]))
            ans[len-2] = 2;
        if(a[len-1] == '0')
            {
            ans[len-1] = 0;
            ans[len-2] = 1;
            }
        if(a[len-2] == '0')
            ans[len-2] = ans[len-1];

        for(i=len-3; i>=0; i--)
            {
            ans[i] = ans[i+1];
            if(chk(a[i], a[i+1]))
                ans[i] += ans[i+2];
            if(a[i] == '0')
                ans[i] = ans[i+2];
            }

        // for(i=0; i<len; i++)
        //     cout<<ans[i]<<" ";
        // cout<<"\n";

        cout<<ans[0]<<"\n";
        }
    return 0;
}
