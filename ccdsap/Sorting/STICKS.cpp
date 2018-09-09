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
                if(a[i] > 3)
                    second = i;
                --i;
                break;
            }
        }
        if(second == 0) {
            for(; i>0; i--) {
                if(a[i] > 1) {
                    second = i;
                    break;
                }
            }
        }
        cout<<(first*second == 0 ? -1: first*second)<<"\n";
    }
    return 0;
}