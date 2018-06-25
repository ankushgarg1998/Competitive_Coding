#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
using namespace std;

int main()
    {
    long int n, a[210], gap=0, intersections=0;
    cin>>n;
    loop(i, 0, 2*n) {
        cin>>a[i];
    }
    loop(i, 1, n+1) {
        loop(j, 0, 2*n) {
            if(a[j] == i) {
                long int gg = 0, ii = 0;
                // set<int> s;
                int inter[110]={0};
                loop(k, j+1, 2*n) {
                    if(a[k] == i) {
                        gap += gg;
                        intersections += ii;
                        break;
                    }
                    // if(s.find(a[k]) == s.end() {
                    if(inter[a[k]] == 0) {
                        ++gg;
                        ++ii;
                        // s.insert(a[k]);
                        inter[a[k]] = i;
                    }
                    else {
                        ++gg;
                        --ii;
                    }
                }
            break;
            }
        }
    }
    // cout<<gap<<" "<<intersections<<"\n";
    cout<<gap-(intersections/2)<<"\n";
    return 0;
    }