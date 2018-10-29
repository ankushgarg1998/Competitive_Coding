#include <iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int n;
int print(int *arr, char ch='Q') {
    cout<<ch<<" ";
    loop(i, 0, n)
        cout<<arr[i]<<" ";
    cout<<"\n";
    int c;
    if(ch == 'Q') {
        cin>>c;
        return c;
    } else
        return 0;
}

int main() {
    cin>>n;
    int arr[n] = {0};
    int x = print(arr);
    x = n-x;
    loop(i, 0, n) {
        if(x==0)
            break;
            
        arr[i] = 1;
        if((n-print(arr)) < x) {
            --x;
        } else
            arr[i] = 0;
    }
    int b = print(arr, 'A');
    return 0;
}