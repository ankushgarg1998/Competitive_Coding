#include <bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init(arr,val) memset(arr,val,sizeof(arr))
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
    test {
        cin>>n;
        int arr[n] = {0};
        int x = print(arr);
        if(x > (n/2)) {
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
        } else {
            loop(i, 0, n)
                arr[i] = 1;
            loop(i, 0, n) {
                if(x==0)
                    break;
                    
                arr[i] = 0;
                if((n-print(arr)) < x) {
                    --x;
                } else
                    arr[i] = 1;
            }
        }
        int b = print(arr, 'A');
    }
    return 0;
}