#include<iostream>
#include<climits>
using namespace std;

int main()
    {
    long int n;
    long int a, b, c, x;
    long int arr[100001];
    // arr[0] = 0;
    arr[1] = 0;
    cin>>n>>a>>b>>c;
    // x = 2*n;
    for(int i=2; i<=n; i++)
        {
        if(i&1)
            arr[i] = min(arr[i-1]+b, arr[(i+1)/2]+a+c);
        else
            arr[i] = min(arr[i-1]+b, arr[i/2]+a);
        }
    cout<<arr[n];
    return 0;
    }