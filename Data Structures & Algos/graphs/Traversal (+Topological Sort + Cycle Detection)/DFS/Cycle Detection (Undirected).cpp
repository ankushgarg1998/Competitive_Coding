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

        bool isCyclicHelper(T node, map<T, bool> &visited, T parent)
            {
            visited[node] = true;

            for(T neighbor: adjList[node])
                {
                if(!visited[neighbor])
                    {
                    bool cycleDetected = isCyclicHelper(neighbor, visited, node);
                    if(cycleDetected)
                        return true;
                    }
                else if(neighbor != parent)
                    return true;
                }
            }

        bool isCyclicDFS()
            {
            map<T, bool> visited;
            
            // You can call for finding cycle in every dfs tree
            for(auto i: adjList)
                {
                T node = i.first;
                if(!visited[node])
                    {
                    bool ans = isCyclicHelper(node, visited, node);
                    if(ans == true)
                        return true;
                    }
                }
            return false;
            }
    };

int main()
    {
    Graph<int> g;
    
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    
    if(g.isCyclicDFS())
        cout<<"Cyclic";
    else
        cout<<"Non Cyclic";
    
    return 0;
    }