#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main()
    {
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0; i<m; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    int mini = INT_MAX;
    for(int i=0; i<=m-n; i++)
        {
        mini = min(v[i+n-1] - v[i], mini);
        }
    cout<<mini<<"\n";
    return 0;
    }