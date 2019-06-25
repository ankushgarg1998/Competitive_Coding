#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define loopm(i,a,b,step) for(int i=a;i<b;i+=step)
#define loopbm(i,a,b,step) for(int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
using namespace std;

int main()
    {
    int n, k;
    test
        {
        cin>>n;
        vector<pair<li, li> > a(n);
        vector<bool> blocked(n+1, false);
        blocked[n] = true;
        for(auto &x: a)
            cin>>x.first>>x.second;
        sort(a.begin(), a.end());

        vector<pair<li, li> > b(n);
        loop(i, 0, n)
            {
            b[i].first = a[i].second;
            b[i].second = i;
            }
        sort(b.begin(), b.end());

        // ioi = index of indexes
        vector<int> ioi(n);
        loop(i, 0, n)
            ioi[b[i].second] = i;

        int ptr = -1;
        lli val = 0;
        lli sum = 0;
        int ans = 0;
        loop(i, 0, n)
            {
            sum += b[i].first;
            if((i+1)*a[0].first >= sum)
                {
                val = sum;
                ptr = i;
                }
            else
                break;
            }
        
        ans = ptr + 1;
        int num = ans;
        sum = val;
        loop(i, 1, n)
            {
            int unwantedi = ioi[i-1];
            if(unwantedi <= ptr)
                {
                sum -= b[unwantedi].first;
                blocked[unwantedi] = true;
                --num;
                }
            else
                blocked[unwantedi] = true;

            while(ptr < n-1)
                {
                if(!blocked[ptr+1])
                    {
                    val = sum + b[ptr+1].first;
                    if((num+1)*a[i].first >= val)
                        {
                        sum = val;
                        ++num;
                        ++ptr;
                        }
                    else    
                        break;
                    }
                else
                    ++ptr;
                }
            ans = max(ans, num);
            }
        cout<<ans<<"\n";
        }
    return 0;
    }