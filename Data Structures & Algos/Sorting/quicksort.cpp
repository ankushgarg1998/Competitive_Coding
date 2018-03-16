#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
    {
    int i=s-1, pivot = arr[e];
    for(int j=s; j<e; j++)
        {
        if(arr[j] < pivot)
            {
            ++i;
            swap(arr[i], arr[j]);
            }
        }
    swap(arr[e], arr[i+1]);
    return (i+1);
    }

void quicksort(int *arr, int s, int e)
    {
    if(s >= e)
        return;
    int p = partition(arr, s, e);
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
    }

int main() {
    int a[15], i, n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    quicksort(a, 0, n-1);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
}

