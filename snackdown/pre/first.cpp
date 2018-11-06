#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main()
    {
    test {
        int n1, m1, n, m;
        li x;
        cin>>n1>>m1;
        vector<li> a, b;
        loop(i, 0, n1) {
            cin>>x;
            if(x != 0)
                a.push_back(x);
        }
        loop(i, 0, m1) {
            cin>>x;
            if(x != 0)
                b.push_back(x);
        }

        n = a.size();
        m = b.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(n != m) {
            cout<<"Alice\n";
        } else {
            char ans = 'b';
            loop(i, 0, n) {
                if(a[i] != b[i]) {
                    ans = 'a';
                    cout<<"Alice\n";
                    break;
                }
            }
            if(ans == 'b')
                cout<<"Bob\n";
        }
    }
    return 0;
    }