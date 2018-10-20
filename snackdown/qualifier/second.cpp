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
using namespace std;

set<int> semis;
bool prime[250];

void find_primes() {
    init(prime, true);
    loop(i, 2, 210) {
        if(prime[i]) {
            int x = i+i;
            while(x < 210) {
                prime[x] = false;
                x += i;
            }
        }
    }

    // making set for semis
    loop(i, 2, 100) {
        if(prime[i]) {
            loop(j, i+1, 100) {
                if(prime[j] && (i*j) <= 200)
                    semis.insert(i*j);
            }
        }
    }
}

int main() {
    find_primes();
    test {
        int n;
        cin>>n;
        bool ans = false;
        loop(i, 1, n) {
            if(semis.find(i) != semis.end()) {
                if(semis.find(n-i) != semis.end()) {
                    ans = true;
                    break;
                }
            }
        }
        if(ans)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
    return 0;   
}