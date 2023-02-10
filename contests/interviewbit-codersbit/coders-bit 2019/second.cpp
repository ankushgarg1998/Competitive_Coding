#include<bits/stdc++.h>
using namespace std;

int main() {
    string A = "apds";
    set<string> s;
    for(int j=0; j<A.size(); j++) {
        for(int i=j; i<A.size(); i++) {
            if(A[i] <= A[j]) {
                string g = string(A);
                reverse(g.begin()+j, g.begin()+i+1);
                s.insert(g);
            }
        }
    }
    for(string str: s)
        cout<<str<<"\n";
    string ans = *s.begin();
    cout<<"ans "<<ans;
}