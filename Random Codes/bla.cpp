#include<iostream>
#include<set>
using namespace std;
int main()
    {
    long int n, m, i;
    long long int a[1000005];
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];
    a[0] = 0;
    for(i=1; i<=n; i++)
        a[i] = (a[i]+a[i-1]) % m;
    set<int> s;
    for(i=0; i<=n; i++)
        {
        if(s.find(a[i]) == s.end())
            s.insert(a[i]);
        else
            {
            cout<<"YES";
            return 0;
            }
        }
    cout<<"NO";
    return 0;
    }
