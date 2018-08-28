#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str;
    stack<char> s;
    cin>>str;
    int count = 0, maxi = 0, maxmax = 0;
    for(char ch: str) {
        if(s.empty() && ch==')') {
            cout<<maxi<<"\n";
            if(maxmax == maxi)
                ++count;
            else if(maxi > maxmax) {
                maxmax = maxi;
                count = 1;
            }
            maxi = 0;
        }
        else if(ch == '(') {
            s.push('(');
        } else {
            s.pop();
            ++maxi;
        }
    }
    if(maxmax == maxi)
        ++count;
    else if(maxi > maxmax) {
        maxmax = maxi;
        count = 1;
    }
    cout<<2*maxmax<<" "<<(maxmax == 0? 1: count)<<'\n';
    return 0;
}