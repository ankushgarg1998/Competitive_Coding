#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;

int main() {
    int a[110], n; 
    test {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];

        int i=0, j=0, ct[10]={0};
        while(++i<8 && j<n) {
            while(a[j]==i && j<n) {
                ++ct[i];
                ++j;
            }
            if(ct[i] == 0) {
                break;
            }
        }
        if(i != 8) {
            cout<<"no\n";
            continue;
        }
        --i;
        while(--i>0 && j<n) {
            while(a[j]==i && j<n) {
                --ct[i];
                ++j;
            }
            if(ct[i] != 0) {
                break;
            }
        }
        if(i != 0) {
            cout<<"no\n";
            continue;
        } else {
            cout<<"yes\n";
        }
    }
    return 0;
}