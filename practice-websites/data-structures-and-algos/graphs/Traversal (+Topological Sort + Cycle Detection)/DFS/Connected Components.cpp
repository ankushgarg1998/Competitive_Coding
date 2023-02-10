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
            int component = 1;
            dfsHelper(src, visited);
            cout<<endl;

            for(auto i: adjList)
                {
                T city = i.first;
                if(!visited[city])
                    {
                    dfsHelper(city, visited);
                    cout<<endl;
                    ++component;
                    }
                }
            cout<<"The Graph had "<<component<<"connected components.";
            }
    };

int main()
    {
    Graph<string> g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Banglore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");
    g.dfs("Amritsar");
    return 0;
    }