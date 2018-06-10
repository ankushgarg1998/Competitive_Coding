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

        void topologicalSort()
            {
            queue<T> q;
            map<T, bool> visited;
            map<T, int> indegree;

            for(auto i:adjList)
                {
                // i is a pair of node and its list
                T node = i.first;
                visited[node] = false;
                indegree[node] = 0;
                }

            // Init Indegree of all nodes
            for(auto i: adjList)
                {
                T u = i.first;
                for(T v: adjList[u])
                    indegree[v]++;
                }

            // Find out all the nodes with 0 indegree
            for(auto i: adjList)
                {
                T node = i.first;
                if(indegree[node] == 0)
                    q.push(node);
                }

            // Start with algo
            while(!q.empty())
                {
                T node = q.front();
                q.pop();
                cout<<node<<" -->";

                for(T neighbor:adjList[node])
                    {
                    indegree[neighbor]--;

                    if(indegree[neighbor] == 0)
                        q.push(neighbor);
                    }
                }
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

    g.topologicalSort();
    return 0;
    }