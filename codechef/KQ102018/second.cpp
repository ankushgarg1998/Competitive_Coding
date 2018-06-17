#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph
    {
    map<T, list<T> > adjList;
    public:
        void addEdge(T u, T v, bool bidir = true)
            {
            adjList[u].push_back(v);
            if(bidir)
                adjList[v].push_back(u);
            }

        void printAdjList()
            {
            for(auto x: adjList)
                {
                cout<<x.first<<" : ";
                for(T y: x.second)
                    cout<<y<<", ";
                cout<<endl;
                }
            }

        void dfsHelper(T node, map<T, bool> &visited)
            {
            // Whenever come to a node, mark it visited
            visited[node] = true;
            // cout<<node<<" ";

            // Go to next node
            for(T neighbor: adjList[node])
                {
                if(!visited[neighbor])
                    dfsHelper(neighbor, visited);
                }
            }

        int dfs(T src)
            {
            map<T, bool> visited;
            int component = 1;
            dfsHelper(src, visited);
            // cout<<endl;

            for(auto i: adjList)
                {
                T city = i.first;
                if(!visited[city])
                    {
                    dfsHelper(city, visited);
                    // cout<<endl;
                    ++component;
                    }
                }
            return component;
            }
    };

int main()
    {
    Graph<int> g[11];
    int n, x, ans = 0, a[20][20], z = 100;
    cin>>n;
    for(int i=1; i<=n; i++)
        {
        for(int j=1; j<=n; j++)
            {
            cin>>a[i][j];
            }
        }
    for(int yo=1; yo<=n; yo++)
        {
        for(int i=1; i<=n; i++)
            {
            for(int j=1; j<=n; j++)
                {
                if(i != yo && j != yo)
                    {
                    if(a[i][j] == 1)
                        g[yo].addEdge(i, j);
                    }
                else
                    {
                    g[yo].addEdge(i, ++z);
                    g[yo].addEdge(j, ++z);
                    }
                }
            }
        int l = g[yo].dfs(1);
        // cout<<yo<<": "<<l<<"\n";
        ans = max(ans, l);
        }
    cout<<ans<<"\n";
    return 0;
    }