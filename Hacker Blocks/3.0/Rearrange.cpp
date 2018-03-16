#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, x, temp, i;
    vector<int> v;
    cin>>n;
    for(i=0; i<n; i++)
        {
        cin>>x;
        v.push_back(x);
        }
    for(i=0; i<n/2; i++)
        {
        if(! (i&1))
            {
            temp = v[i];
            v[i] = v[n-i-1];
            v[n-i-1] = temp;
            }
        }
    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
	return 0;
}
