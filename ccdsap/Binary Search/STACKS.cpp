#include <bits/stdc++.h>
#define li long int
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std; 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        li x;
        vector<li> v(1);
        cin>>v[0];
        loop(i, 1, n) {
            cin>>x;
            int start=0, end=v.size()-1, mid, ans=-1;
            while(start <= end) {
                mid = (start+end)/2;
                if(v[mid] > x) {
                    ans = mid;
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
            if(ans == -1)
                v.push_back(x);
            else
                v[ans] = x;
        }
        cout<<v.size();
        loop(i, 0, v.size())
            cout<<" "<<v[i];
        cout<<"\n";
    }
    return 0;
}
