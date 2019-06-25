#include <bits/stdc++.h>  
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
using namespace std; 
  
struct Stars { 
    int s, f, d; 
};

bool comp(Stars s1, Stars s2) { 
    return (s1.f < s2.f); 
} 

int last(Stars arr[], int i) { 
    for (int j=i-1; j>=0; j--) { 
        if (arr[j].f <= arr[i].s) 
            return j;
    }
    return -1; 
} 

int solve(Stars arr[], int n) {
    sort(arr, arr+n, comp); 

    // loop(i, 0, n) {
    //     cout<<arr[i].s<<" "<<arr[i].f<<" "<<arr[i].d<<"\n";
    // }
  
    int *table = new int[n]; 
    table[0] = arr[0].d; 

    int ans = 0;
    for (int i=1; i<n; i++) { 
        int temp = arr[i].d; 
        int l = last(arr, i); 
        if (l != -1) 
            temp += table[l]; 
  
        table[i] = max(temp, table[i-1]); 
        ans = max(ans, table[i]);
    }   
    return ans; 
} 
  
int main() { 
    int n;
    cin>>n;
    Stars arr[n];
    loop(i, 0, n) {
        cin>>arr[i].s>>arr[i].f>>arr[i].d;
    }
    cout<<solve(arr, n); 
    return 0; 
} 