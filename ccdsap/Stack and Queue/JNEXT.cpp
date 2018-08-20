#include<iostream>
#include<vector>
#include<algorithm>
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    test {
        int n;
        cin>>n;
        vector<int> v(n);
        loop(i, 0, n)
            cin>>v[i];

        int i;
        for(i=n-1; i>0; i--) {
            if(v[i] > v[i-1]) {
                int sw = i;
                loop(j, i, n) {
                    if(v[j] > v[i-1]) {
                        if(v[sw] > v[j])
                            sw = j;
                    }
                }
                swap(v[sw], v[i-1]);
                sort(v.begin()+i, v.end());
                break;
            }
        }
        if(i == 0)
            cout<<"-1";
        else {
        loop(i, 0, n)
            cout<<v[i];
        }
        cout<<"\n";
    }
    return 0;
}