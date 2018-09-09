#include <iostream>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int party(int *a, int l, int r) {
    int p = a[r-1];
    int less = l-1;

    loop(i, l, r-1) {
        if(a[i] < p) {
            ++less;
            swap(a[i], a[less]);
        }
    }
    ++less;
    swap(a[less], a[r-1]);
    return less;
}

void quickSort(int *arr, int l, int r) {
    if(r-l < 2) {
        return;
    }
    int pi = party(arr, l, r);

    quickSort(arr, l, pi);
    quickSort(arr, pi+1, r);
}

int main() {
    int arr[100], n;
    cin>>n;
    loop(i, 0, n)
        cin>>arr[i];
    quickSort(arr, 0, n);
    loop(i, 0, n)
        cout<<arr[i]<<" ";
    return 0;
}
