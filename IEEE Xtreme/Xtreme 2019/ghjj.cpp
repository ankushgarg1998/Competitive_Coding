#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(2*(n+1), -1);
    int i=1;
    while(i+1 <= 2*n) {
        cout<<i<<" "<<i+1<<"\n";
        string s;
        int a, b;
        cin>>s;
        if(s != "MATCH") {
            a = stoi(s);
            cin>>b;
            v[i] = a;
            v[i+1] = b;
        }
        i += 2;
    }
    vector<int> bec(n+1, -1);
    loop(i, 1, 2*n+1) {
        int x = v[i];
        if(x != -1) {
            if(bec[x] == -1)
                bec[x] = i;
            else {
                cout<<bec[x]<<" "<<i<<"\n";
                string s;
                cin>>s;
            }
        }
    }
    cout<<"-1\n";
    return 0;
}