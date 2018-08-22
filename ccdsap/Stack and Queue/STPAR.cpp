#include <iostream>
#define loop(i, a, b) for(int i=a; i<b; i++)
#include<stack>
#include<queue>

using namespace std;
int main() {
    int n, x;
    while(true) {
        cin>>n;
        if(n == 0)
            return 0;

        queue<int> q;
        loop(i, 0, n) {
            cin>>x;
            q.push(x);
        }

        stack<int> s;
        int i=0;
        bool ans = true;
        while(++i<=n) {
            if(q.front() == i)
                q.pop();
            else if(!s.empty()) {
                if(s.top() == i)
                    s.pop();
                else {
                    if(q.empty()) {
                        ans = false;
                        break;
                    }
                    --i;
                    s.push(q.front());
                    q.pop();
                }
            }
            else {
                if(q.empty()) {
                    ans = false;
                    break;
                }
                --i;
                s.push(q.front());
                q.pop();
            }
        }
        if(ans)
            cout<<"yes";
        else
            cout<<"no";
        cout<<"\n";
    }
    return 0;
}
