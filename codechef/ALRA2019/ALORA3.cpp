#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dfs(vector<int> *v, int source) {
    bool visited[26] = {0};
    stack<int> s;
    visited[source] = true;
    s.push(source);
    int minimum = source;
    while(!s.empty()) {
        int x = s.top();
        minimum = min(x, minimum);
        s.pop();
        for(int &i: v[x]) {
            if(!visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    return minimum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    test {
        int L, m;
        string s;
        cin>>L>>m;
        cin>>s;
        vector<int> v[26];
        while(m--) {
            char a, b;
            cin>>a>>b;
            v[(a-'a')].push_back(b-'a');
        }

        int minimum[26];
        loop(i, 0, 26) {
            minimum[i] = dfs(v, i);
        }

        loop(i, 0, s.size()) {
            if(minimum[s[i] - 'a'] < (s[i] - 'a'))
                s[i] = (char)(minimum[s[i] - 'a'] + 'a');
        }

        cout<<s<<"\n";
    }
    return 0;
}