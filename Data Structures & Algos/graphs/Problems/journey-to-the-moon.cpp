#include<iostream>
#include<list>
#define int long long int
using namespace std;

class Graph {
    int V;
    list<int> *l;

    public:
        Graph(int v) {
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int u, int v) {
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void dfsHelper(int i, bool visited[], int &country_size) {
            visited[i] = true;
            ++country_size;
            for(auto neighbour: l[i]) {
                if(!visited[neighbour])
                    dfsHelper(neighbour, visited, country_size);
            }
        }

        int dfsMoon() {
            bool *visited = new bool[V];
            for(int i=0; i<V; i++)
                visited[i] = false;

            int n = V;
            int total_ways = (n*(n-1))/2;

            for(int i=0; i<V; i++) {
                if(!visited[i]) {
                    int country_size = 0;
                    dfsHelper(i, visited, country_size);
                    // cout<<"Country Size"<<country_size<<"\n";
                    total_ways -= (((country_size)*(country_size-1))/2);
                }
            }
            return total_ways;
        }
};

#undef int
int main() {
    long long int n, k, a, b;
    cin>>n>>k;
    Graph g(n);
    while(k--) {
        cin>>a>>b;
        g.addEdge(a, b);
    }
    cout<<g.dfsMoon()<<"\n";
}