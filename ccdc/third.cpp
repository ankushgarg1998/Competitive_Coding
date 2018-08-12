#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

int main()
    {
    string s;
    int qb, qs, qc;
    int nb, ns, nc;
    int pb, ps, pc;
    int r, ans = 0;
    cin>>s;
    loop(i, 0, s.size()) {
        if(s[i] == 'B') {
            ++qb;
        } else if(s[i] == 'S') {
            ++qs;
        } else {
            ++qc;
        }
    }
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    int fb, fs, fc;
    fb = nb/qb;
    fs = ns/qs;
    fc = nc/qc;
    nb = nb%qb;
    ns = ns%qs;
    nc = nc%qc;
    if(min(fb, min(fs, fc)) == fb) {
        ans += fb;
        fb -= fb;
        fs -= fb;
        fc -= fb;
        if(fs < fc) {
            int hb = r/pb;
            hb += nb;
            hb /= qb;
            if(hb > fs) {
                ans += fs;
                fs -= fs;
                fc -= fs;
                r -= (fs*pb*qb);

                
            } else {
                ans += hb;
                return 0;
            }
        } else {

        }
    } else if (min(fb, min(fs, fc)) == fs) {
        if(fb < fc) {

        } else {

        }
    } else {
        if(fb < fs) {

        } else {

        }
    }

    return 0;
    }