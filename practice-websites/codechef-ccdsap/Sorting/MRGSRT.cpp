#include <iostream>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int depth, key;

void mergeSort(int *a, int l, int r) {
    if(l<=key && key<=r) {
        ++depth;
        cout<<l<<" "<<r<<"\n";
        if(l==key && r==key) {
            cout<<depth<<"\n";
            return;
        }
        if(r == l)
            return;
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        // merge(a, l, mid+1, r);
    } else
        return;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b, c;
        cin>>a>>b>>c;
        key = c;
        if(c>=a && c<=b) {
            depth = 0;
            int arr[1010];
            mergeSort(arr, a, b);
        } else {
            cout<<"-1\n";
        }
    }
    return 0;
}
