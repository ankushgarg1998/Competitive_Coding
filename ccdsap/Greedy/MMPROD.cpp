// zero
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define lli long long int
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

bool cmp(const int &a, const int &b) {
    return (abs(a)>abs(b));
}

int main() {
    test {
        int n, k;
        cin>>n>>k;
        int j = k-1, negin = -1, negout = -1, posin = -1, posout = -1;
        lli first = -1, second = -1;
        lli ans = 1;
        lli a[n];

        loop(i, 0, n)
            cin>>a[i];
        
        sort(a, a+n, cmp);

        int negs = 0;
        loop(i, 0, k) {
            if(a[i] < 0)
                ++negs;
        }
        if(negs%2 == 0)
            goto solve;

        
        
        for(j = k-1; j>=0; j--) {
            if(a[j] < 0) {
                negin = j;
                break;
            }
        }
        j = k;
        for(; j<n; j++) {
            if(a[j] > 0) {
                posout = j;
                first = 1;
                break;
            }
        }
        // if(posout == -1) {
        //     first = -1;
        // }


        j = k-1;
        for(; j>=0; j--) {
            if(a[j] > 0) {
                posin = j;
                break;
            }
        }
        if(posin == -1) {
            second = -1;
        } else {
            j = k;
            for(; j<n; j++) {
                if(a[j] < 0) {
                    negout = j;
                    second = 1;
                    break;
                }
            }
            // if(negout == -1) {
            //     second = -1;
            // }
        }

        if(first == -1 && second == -1) {
            loop(i, n-k, n) {
                ans *= a[i];
                ans %= MOD;
            }
            cout<<(ans < 0? ans+MOD: ans)<<"\n";
            continue;
        } else if(first == -1) {
            swap(a[posin], a[negout]);
            goto solve;
        } else if(second == -1) {
            swap(a[negin], a[posout]);
        } else {
            if(a[posin]*a[posout] > a[negin]*a[negout])
                swap(a[negin], a[posout]);
            else
                swap(a[posin], a[negout]);
        }
        

        solve:
        loop(i, 0, k) {
            ans *= a[i];
            ans %= MOD;
        }
       
        cout<<(ans < 0? ans+MOD: ans)<<"\n";
    }
    return 0;
}