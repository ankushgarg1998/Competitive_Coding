#include <iostream>
using namespace std;

void merge(int *arr, int s1, int e1, int s2, int e2)
    {
    int a[100], k=0, i, j;
    for(i=s1, j=s2; i<=e1 && j<=e2;)
        {
        if(arr[i] < arr[j])
            {
            a[k] = arr[i];
            ++i;
            }
        else
            {
            a[k] = arr[j];
            ++j;
            }
        ++k;
        }
    while(i<=e1)
        {
        a[k] = arr[i];
        ++i; ++k;
        }
    while(j<=e2)
        {
        a[k] = arr[j];
        ++j; ++k;
        }
    for(i=s1, j=0; j<k; j++, i++)
        arr[i] = a[j];

    }

void mergesort(int *arr, int s, int e)
    {
    if(s >= e)
        return;
    mergesort(arr, s, (s+e)/2);
    mergesort(arr, ((s+e)/2)+1, e);
    merge(arr, s, (s+e)/2, ((s+e)/2)+1, e);
    }

int main() {
    int a[15], i, n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    mergesort(a, 0, n-1);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
}
