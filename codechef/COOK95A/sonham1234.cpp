#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define loopm(i,a,b,step) for(int i=a;i<b;i+=step)
#define loopbm(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define INF 1000000007
#define MOD 1000000007
#define BINF 1000000000000000001
#define int long long int
#define double long double
    
using namespace std;


    
    
    
#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        pair<int,int>x[n];
        
        loop(i,0,n) cin>>x[i].first>>x[i].second;
        
        sort(x,x+n);
        
        pair<int,int>b[n];
        loop(i,0,n)
        {
            b[i].first=x[i].second;
            b[i].second=i;
        }
        
        sort(b,b+n);
        
        int gone[n];
        loop(i,0,n)
        {
            gone[b[i].second]=i;
        }
        
        bool blocked[n+1];
        fill(blocked,blocked+n+1,false);
        blocked[n]=true;
        
        
        /*loop(i,0,n) cout<<x[i].first<<" ";
        cout<<endl;
        loop(i,0,n) cout<<b[i].first<<" ";
        cout<<endl;
        exit(0);*/
        
        int ans=0;
        
        int sum=0;
        int ptr=-1;
        
        loop(i,0,n)
        {
            int val=sum+b[i].first;
            if((i+1)*x[0].first>=val)
            {
                sum=val;
                ptr=i;
            }
            
            else
            {
                break;
            }
            
        }
        
        
        ans=ptr+1;
        int num=ptr+1;
        
        loop(i,1,n)
        {
            int there=gone[i-1];
            if(there<=ptr)
            {
                sum-=b[there].first;
                blocked[there]=true;
                num--;
            }
            else
            {
                blocked[there]=true;
            }
            
            while(ptr<n-1)
            {
                if(blocked[ptr+1]==true) ptr++;
                else
                {
                    int val=sum+b[ptr+1].first;
                    if(x[i].first*(num+1)>=val)
                    {
                        num++;
                        ptr++;
                        sum=val;
                        
                    }
                    else break;
                }
                
            }
            ans=max(ans,num);
        }
        
        cout<<ans<<"\n";
        
        
    }
    
    return 0;
}