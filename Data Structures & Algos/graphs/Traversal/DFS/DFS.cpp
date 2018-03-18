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
            cout<<node<<" ";

            // Go to next node
            for(T neighbor: adjList[node])
                {
                if(!visited[neighbor])
                    dfsHelper(neighbor, visited);
                }
            }

        void dfs(T src)
            {
            map<T, bool> visited;
            dfsHelper(src, visited);
            }
    };

int main()
    {
    Graph<string> g;
    g.addEdge("Putin", "Trump", false);
    g.addEdge("Putin", "Modi", true);
    g.addEdge("Putin", "Pope", false);
    g.addEdge("Modi", "Trump", true);
    g.addEdge("Modi", "Yogi", true);
    g.addEdge("Yogi", "Prabhu", false);
    g.addEdge("Prabhu", "Modi", false);
    g.dfs("Modi");
    return 0;
    }