#include <iostream>
using namespace std;
long int count = 0;

void merge(long int *arr, long int s1, long int e1, long int s2, long int e2)
    {
    long int a[1000000], k=0, i, j;
    for(i=s1, j=s2; i<=e1 && j<=e2;)
        {
        if(arr[i] < arr[j])
            {
            a[k] = arr[i];
            ++i;
            }
        else
            {
            count += (e1-i+1);
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

void mergesort(long int *arr, long int s, long int e)
    {
    if(s >= e)
        return;
    mergesort(arr, s, (s+e)/2);
    mergesort(arr, ((s+e)/2)+1, e);
    merge(arr, s, (s+e)/2, ((s+e)/2)+1, e);
    }

long int main() {
    long int a[1000000], i, n, t;
    cin>>t;
    while(t--)
        {
        count = 0;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        mergesort(a, 0, n-1);
        // for(i=0; i<n; i++)
        //     cout<<a[i]<<" ";
        cout<<count<<"\n";
        }
    return 0;
}
