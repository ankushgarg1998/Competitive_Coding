#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 8;
    
    // MANUAL
    int f=0, l=n-1, ans = -1;
    while(f<=l) {
        int m = (f+l)/2;
        if(arr[m] == x) {
            ans = m;
            break;
        } else if(arr[m] < x)
            f = m+1;
        else
            l = m-1;
    }

    // BUILT IN FUNCTION (just presence or absence)
    // int ans = binary_search(arr, arr+n, x);
    
    cout<<ans<<"\n";
    return 0;
}