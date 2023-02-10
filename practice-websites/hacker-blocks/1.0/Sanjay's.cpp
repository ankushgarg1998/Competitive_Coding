#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sortbysecdesc(const pair<string, int>& a, const pair<string, int> &b)
    {
    return (a.second > b.second);
    }
    
int main() {
    int x;
    long int N, i;
    string name;
    int salary;
    vector< pair<string, int> > arr;
    cin>>x>>N;
    for(i=0; i<N; i++)
        {
        cin>>name;
        cin>>salary;
        arr.push_back(make_pair(name, salary));
        }
    
    sort(arr.begin(), arr.end());
    sort(arr.begin(), arr.end(), sortbysecdesc);
    
    for(i=0; i<N; i++)
        {
        if(arr[i].second >= x)
            cout<<arr[i].first<<" "<<arr[i].second<<"\n";
        }
        
    return 0;
}
