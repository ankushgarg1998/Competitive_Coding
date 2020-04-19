#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
#define li long int
#define MOD 1000000007
#define testing int test; cin>>test; for(int t=1; t<=test; t++)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
lli power(lli a, lli p) { lli ans=1; while(p>0) { if(p&1) ans*=a; p>>=1; a*=a; } return ans; }
lli power(lli a, lli p, lli mod) { lli ans=1; while(p>0) { if(p&1) ans = (ans*a)%mod; p>>=1; a = (a*a)%mod; } return ans; }

// 0 > no change

// 1 comp > same -> comp
//          diff -> comp

// 2 rev >  same -> same
//          diff -> comp

// 3 c+r >  same -> comp
//          diff -> same


int queryNumber;
int diffIndex = -1, sameIndex = -1;
int diffIndexVal = -1, sameIndexVal = -1;

int query(int index) {
    int x;
    cout<<index<<"\n";
    cin>>x;
    ++queryNumber;
    return x;
}

void comp(vector<int> &v) {
    loop(i, 1, v.size()) {
        if(v[i] != -1) {
            v[i] = (v[i] == 1? 0: 1);
        }
    } 
}

void rev(vector<int> &v) {
    loop(i, 1, (v.size()+1)/2) {
        int temp = v[i];
        v[i] = v[v.size()-i];
        v[v.size()-i] = temp;
    }
}
        
void updateVector(vector<int> &v) {
    if(diffIndex == -1) {
        int currentVal = query(sameIndex);
        if(sameIndexVal != currentVal) {
            sameIndexVal = currentVal;
            comp(v);
        }
        int temp = query(1);
    } else if(sameIndex == -1) {
        int currentVal = query(diffIndex);
        if(diffIndexVal != currentVal) {
            diffIndexVal = currentVal;
            comp(v);
        }
        int temp = query(1);
    } else {
        int currentSameVal = query(sameIndex);
        int currentDiffVal = query(diffIndex);
        if(sameIndexVal != currentSameVal) {
            sameIndexVal = currentSameVal;
            comp(v);
            if(diffIndexVal == currentDiffVal) {
                rev(v);
            } else {
                diffIndexVal = currentDiffVal;
            }
        } else if(diffIndexVal != currentDiffVal) {
            diffIndexVal = currentDiffVal;
            rev(v);
        }
    }
}

int main() {
    int t, b, x;
    string s;
    cin>>t>>b;
    while(t--) {
        vector<int> ans(b+1, -1);
        diffIndex = -1; sameIndex = -1;
        diffIndexVal = -1; sameIndexVal = -1;
        queryNumber = 1;
        loop(i, 1, (b/2)+1) {
            
            if(queryNumber%10 == 1 && queryNumber != 1) {
                updateVector(ans);
            }
    
            ans[i] = query(i);
            ans[b+1-i] = query(b+1-i);

            if(ans[i] == ans[b+1-i]) {
                sameIndex = i;
                sameIndexVal = ans[i];
            } else {
                diffIndex = i;
                diffIndexVal = ans[i];
            }
        }

        loop(i, 1, b+1)
            cout<<ans[i];
        cout<<"\n";
        cin>>s;
            if(s != "Y")
                break;
    }
    return 0;
}