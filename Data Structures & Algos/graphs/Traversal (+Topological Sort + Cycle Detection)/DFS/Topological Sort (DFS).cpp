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

        void dfsHelper(T node, map<T, bool> &visited, list<T> &ordering)
            {
            // Whenever come to a node, mark it visited
            visited[node] = true;
            // Will call DFS on the unvisited neighbors of the current node
            for(T neighbor: adjList[node])
                {
                if(!visited[neighbor])
                    dfsHelper(neighbor, visited, ordering);
                }
            // Only this line is Topological Sort
            ordering.push_front(node);
            }
            
        void dfsTopologicalSort()
            {
            map<T, bool> visited;
            list<T> ordering;
            for(auto i: adjList)
                {
                // i is a pair (node, list of nodes)
                T node = i.first;
                if(!visited[node])
                    dfsHelper(node, visited, ordering);
                }
            // Print all the elements in ordering
            for(T element: ordering)
                cout<<element<<" --> ";
            }
    };

int main()
    {
    Graph<string> g;
    g.addEdge("English", "Programming Logic", false);
    g.addEdge("Maths", "Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Programming Logic", "JS", false);
    g.addEdge("Python", "Web Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);

    g.dfsTopologicalSort();
    return 0;
    }