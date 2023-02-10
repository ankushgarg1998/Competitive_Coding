#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

int a[100], n;

class Graph {
    unordered_map<int, list<int> > adjList;

    public:
    void addEdge(int i, int j) {
        adjList[i].push_back(j);
        adjList[j].push_back(i);
    }

    void printAdjList() {
        for(auto x: adjList) {
            cout<<"\n"<<a[x.first]<<" -> ";
            for(auto y: x.second)
                cout<<a[y]<<", ";
        }
    }

    int connectedComps() {
        map<int, bool> visited;
        int components = 0;
        loop(i, 0, n) {
            if(!visited[i]) {
                ++components;
                if(components > 1)
                    return 2;
                connectedCompsHelper(i, visited);
            }
        }
        return components;
    }

    void connectedCompsHelper(int src, map<int, bool> &visited) {
        visited[src] = true;
        for(auto x: adjList[src]) {
            if(!visited[x])
                connectedCompsHelper(x, visited);
        }
    }
};

int main() {
    int dp [55][55];
    init(dp, -1);
    test {
        cin>>n;
        bool allEqual = true;
        loop(i, 0, n) {
            cin>>a[i];
            if(a[i] != 47)
                allEqual = false;
        }
        Graph g;
        loop(i, 0, n-1) {
            loop(j, i+1, n) {
                int x;
                if(dp[a[i]][a[j]] == -1) {
                    x = __gcd(a[i], a[j]);
                    dp[a[i]][a[j]] = x;
                    dp[a[i]][a[j]] = x;
                } else
                    x = dp[a[i]][a[j]];
                // cout<<i<<" "<<j<<" "<<x<<"\n";
                if(x == 1) {
                g.addEdge(i, j);
                }
            }
        }
        // g.printAdjList();
        int cc = g.connectedComps();
        int changes = 0;
        if(cc != 1) {
            changes = 1;
            a[0] = (allEqual? 2: 47);
        }
        cout<<changes<<"\n";
        loop(i, 0, n)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}