#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;

vector<int> v;
set<string> se;
int x, n, i;

void sumitup(string s, int i, int sum)
    {
    if(sum==x)
        {
        se.insert(s);
        return;
        }
    if(i==n || sum>x)
        return;
    sumitup(s, i+1, sum);
    sumitup(s + to_string(v[i]) + " ", i+1, sum+v[i]);
    }

int main()
    {
    cin>>n;
    for(i=0; i<n; i++)
        {
        cin>>x;
        v.push_back(x);
        }
    cin>>x;
    sort(v.begin(), v.end());
    sumitup("", 0, 0);
    for(auto a:se)
        cout<<a<<"\n";
    return 0;
    }
