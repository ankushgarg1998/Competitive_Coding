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

        void isCycleBFS(T src)
            {
            queue<T> q;
            map<T, int> parent;
            map<T, bool> visited;

            q.push(src);
            visited[src] = true;
            parent[src] = src;

            while(!q.empty())
                {
                T node = q.front();
                q.pop();

                // Iterate over the neighbors that node leaving parent.
                for(T neighbor: adjList[node])
                    {
                    if(visited[neighbor]==true && parent[node] != neighbor)
                        return true;
                    else if(!visited[neighbor])
                        {
                        visited[neighbor] = true;
                        parent[neighbor] = node;
                        q.push(neighbor);
                        }
                    }
                }
                return false;
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
    g.isCycleBFS("Modi");
    return 0;
    }