#include<iostream>
#define loop(i, a, b) for(int i=0; i<n; i++)
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x, a[1001]={0};
        cin>>n;
        loop(i, 0, n) {
            cin>>x;
            ++a[x];
        }
        int i=1000, first = 0, second = 0;
        for(; i>0; i--) {
            if(a[i] > 1) {
                first = i;
                --i;
                break;
            }
        }
        if(i == 0) {
            cout<<"-1\n";
            continue;
        }
        for(; i>0; i--) {
            if(a[i] > 1) {
                second = i;
                break;
            }
        }
        if(i == 0) {
            cout<<"-1\n";
            continue;
        }
        cout<<first*second<<"\n";
    }
    return 0;
}