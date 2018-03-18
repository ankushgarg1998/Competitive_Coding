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

        void bfs(T src)
            {
            queue<T> q;
            map<T, bool> visited;

            q.push(src);
            visited[src] = true;

            while(!q.empty())
                {
                T node = q.front();
                cout<<node<<" ";

                for(T neighbor : adjList[node])
                    {
                    if(!visited[neighbor])
                        {
                        q.push(neighbor);
                        visited[neighbor] = true;
                        }
                    }

                q.pop();
                }
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
    g.bfs("Modi");
    return 0;
    }