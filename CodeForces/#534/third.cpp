#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    string s;
    cin>>s;
    int a[4][4];
    init(a, 0);
    loop(x, 0, s.size()) {
        bool found = false;
        if(s[x] == '0') {
            loop(j, 0, 4) {
                loop(i, 0, 3) {
                    if(a[i][j] == 0 && a[i+1][j] == 0) {
                        found = true;
                        a[i][j] = 1; a[i+1][j] = 1;
                        cout<<i+1<<" "<<j+1<<"\n";
                        break;
                    }
                }
                if(found)
                    break;
            }
        } else {
            loop(i, 0, 4) {
                loop(j, 0, 3) {
                    if(a[i][j] == 0 && a[i][j+1] == 0) {
                        found = true;
                        a[i][j] = 1; a[i][j+1] = 1;
                        cout<<i+1<<" "<<j+1<<"\n";
                        break;
                    }
                }
                if(found)
                    break;
            }
        }

        loop(i, 0, 4) {
            if(a[i][0]==1 && a[i][1]==1 && a[i][2]==1 && a[i][3]==1) {
                loop(j, 0, 4)
                    a[i][j] = 0;
            }
        }
        loop(j, 0, 4) {
            if(a[0][j]==1 && a[1][j]==1 && a[2][j]==1 && a[3][j]==1) {
                loop(i, 0, 4)
                    a[i][j] = 0;
            }
        }
    }
    return 0;
}