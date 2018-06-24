#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

int main()
    {
    string a, b;
    cin>>a>>b;
    int s = a.length(), count = 0;
    for(int i=0; i<s; i++)
        {
        if(a[i] == '0' && b[i] == '0')
            {
            if(i != 0)
                {
                if(a[i-1] == '0' || b[i-1] =='0')
                    {
                    a[i] = 'X';
                    b[i] = 'X';
                    ++count;
                    }
                else
                    {
                    
                    }
                }
            }
        }
    return 0;
    }