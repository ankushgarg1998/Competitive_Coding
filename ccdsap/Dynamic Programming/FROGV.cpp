#include <iostream>
#include <vector>
#include <algorithm>
#define li long
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    li n, k, p, x;
    cin>>n>>k>>p;
    vector<pair<li, li> > a;
    loop(i, 0, n) {
        cin>>x;
        a.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end());

    li count = 0, arr[n+10];
    arr[a[0].second] = count;
    loop(i, 1, n) {
        if(a[i].first - a[i-1].first <= k)
            arr[a[i].second] = count;
        else
            arr[a[i].second] = ++count;
    }

    // loop(i, 0, n)
    //     cout<<arr[i]<<" ";
    // cout<<"\n";

    li m, j;
    loop(i, 0, p) {
        cin>>m>>j;
        if(arr[m-1] == arr[j-1])
            cout<<"Yes";
        else
            cout<<"No";
        cout<<"\n";
    }
    return 0;
}
