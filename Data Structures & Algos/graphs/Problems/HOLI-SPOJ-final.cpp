#include<iostream>
#include<list>
using namespace std;

class Graph {
    int V;
    list<pair<int, int> > *l;

    public:
        Graph(int v) {
            V = v;
            l = new list<pair<int, int> >[v];
        }

        void addEdge(int u, int v, int w) {
            l[u].push_back(make_pair(v, w));
            l[v].push_back(make_pair(u, w));
        }

        int dfsHelper(int i, bool *visited, int *count, long long int &ans) {
            visited[i] = true;
            count[i] = 1;

            for(auto neighbor: l[i]){
                if(!visited[neighbor.first]) {
                    count[i] += dfsHelper(neighbor.first, visited, count, ans);
                    ans += 2*neighbor.second*min(count[neighbor.first], V-count[neighbor.first]);
                }
            }
            return count[i];
        }

        long long int dfs() {
            bool *visited = new bool[V]{0};
            int *count = new int[V]{0};

            long long int ans = 0;
            dfsHelper(0, visited, count, ans);
            // for(int i=0; i<V; i++) {
            //     cout<<count[i]<<" ";
            // }
            return ans;
        }
};

int main() {
    int t, n, x, y, z;
    cin>>t;
    for(int test=1; test<t+1; test++) {
        cin>>n;
        Graph g(n);
        for(int i=1; i<n; i++) {
            cin>>x>>y>>z;
            g.addEdge(x-1, y-1, z);
        }
        cout<<"Case #"<<test<<": "<<g.dfs()<<"\n";
    }
    return 0;
}

