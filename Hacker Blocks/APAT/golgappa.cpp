#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    long int n, count = 0, i;
    cin>>n;
    vector<long int> v(n);
    for(i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(), v.end());
    for(i=0; i<n; i++)
        count += abs(v[i]-i);
    cout<<count;
	return 0;
}
