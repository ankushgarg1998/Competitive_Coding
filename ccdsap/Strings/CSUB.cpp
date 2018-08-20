#include<iostream>
#define test int t; cin>>t; while(t--)
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    test {
        int n;
        long long int ct=0;
        string s;
        cin>>n;
        cin>>s;
        loop(i, 0, n) {
            if(s[i] == '1')
                ++ct;
        }
        cout<<(ct*(ct+1))/2<<"\n";
    }
    return 0;
}