#include <iostream>
#include <vector>
using namespace std;
int main() {
    long int i, j;
    vector<bool> b(100000, 1);
    b[0] = 0; b[1] = 0;
    for(i = 2; i<=1000; i++)
        {
        if(b[i])
            {
            for(j=(i*i); j<=100000; j+=i)
                b[j] = 0;
            }
        }
    
    // for(i=0; i<=20; i++) cout<<b[i]<<" "<<i<<endl;
    
    int t;
    long int m, n;
    cin>>t;
    while(t--)
        {
        cin>>m>>n;
        vector<bool> v(n-m+1, 1);
        for(i = 2; i*i<=n; i++)
            {
            if(b[i])
                {
                // cout<<i<<" ";
                for(j=m; j<=n; j++)
                    {
                    if(j==i)
                        continue;
                    if(j%i == 0)
                        v[j-m] = 0;
                    }
                }
            }
        for(i=m; i<=n; i++)
            {
            if(v[i-m])
                cout<<i<<"\n";
            }
        cout<<"\n";
        }
    return 0;
}

