#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a, b, c;
vector<int> v(4001, -1);

int dp(int n)
    {
    if(n<0)
        return -5000;
    if(n==0)
        return 0;
    if(v[n] != -1)
        return v[n];
    v[n] =  1+max(dp(n-a), max(dp(n-b), dp(n-c)));
    return v[n];
    }

// int dp(int n)
//     {
//     if(v[n] != -1)
//         return v[n];
//     if(n<a)
//         return 0;
//     int x;
//     if(n>=a)
//         x = 1 + dp(n-a);
//     if(n>=b)
//         x = max(x, 1+dp(n-b));
//     if(n>=c)
//         x = max(x, 1+dp(n-c));
//     v[n] = x;
//     return x;
//     }

int main()
    {
    vector<int> v(3);
    cin>>n;
    for(int i=0; i<3; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    a = v[0]; b = v[1] ; c = v[2];
    cout<<dp(n)<<"\n";
    return 0;
    }