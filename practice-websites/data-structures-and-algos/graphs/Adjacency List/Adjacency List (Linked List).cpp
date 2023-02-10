#include<iostream>
#include<list>
using namespace std;

class Graph
    {
    int V;
    list<int> *arrl;
    public:
        Graph(int v)
            {
            V = v;
            // array of linked list
            arrl = new list<int>[V];
            }
        
        void addEdge(int u, int v, bool bidir=true)
            {
            arrl[u].push_back(v);
            if(bidir)
                arrl[v].push_back(u);
            }
        
        void printAdjList()
            {
            for(int i=0; i<V; i++)
                {
                cout<<i<<" : ";
                for(int vertex: arrl[i])
                    cout<<vertex<<", ";
                cout<<endl;
                }
            }
    };

int main()
    {
    // Graph has 5 vertices 0-4
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);

    g.printAdjList();
    return 0;
    }