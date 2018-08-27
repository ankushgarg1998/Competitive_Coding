#include <iostream>
#include <vector>
#include <stack>
#define lli long long int
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
    while(true) {
        int n;
        cin>>n;
        vector<lli> a(n);
        stack<lli> s;
        lli area = 0;
        if(n == 0)
            break;
        loop(i, 0, n)
            cin>>a[i];

        loop(i, 0, n) {
            if(s.empty() || a[s.top()] <= a[i]) {
                s.push(i);
                // cout<<i<<"\n";
            } else if(a[s.top()] == a[i])
                continue;
            else {
                lli b = 0;
                while(!s.empty() && a[s.top()] > a[i]) {
                    lli h = a[s.top()];
                    s.pop();
                    b = (s.empty() ? i: i - s.top() - 1);
                    // cout<<h<<" "<<b<<"\n";
                    area = max(area, (h*b));
                }
                s.push(i);
                // cout<<i<<"\n";
            }
        }
        lli b=0;
        while(!s.empty()) {
            // int i = s.top();
            lli h = a[s.top()];
            s.pop();
            b = (s.empty() ? n: n - s.top() - 1);
            // cout<<h<<" "<<b<<"\n";
            area = max(area, (h*b));
        }
        cout<<area<<"\n";
    }
    return 0;
}
