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
    int A, B, C, N, x;
    cin>>A>>B>>C>>N;
    if(N < max(A, max(B, C)))
        cout<<-1;
    else if (min(A, B) < C)
        cout<<-1;
    else if (N < ((A+B)-C))
        cout<<-1;
    else
        {
        x = N-((A+B)-C);
        if(x == 0)
            cout<<-1;
        else
            cout<<x;
        }
    cout<<"\n";
    return 0;
    }