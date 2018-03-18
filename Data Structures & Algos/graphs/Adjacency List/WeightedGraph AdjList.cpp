#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T, typename Weight>
class Graph
    {
    map<T, list<pair<T, Weight> > > adjList;
    public:
        void addEdge(T u, T v, Weight w, bool bidir = true)
            {
            
            adjList[u].push_back(make_pair(v, w));
            if(bidir)
                adjList[v].push_back(make_pair(u, w));
            }

        void printAdjList()
            {
            for(auto x: adjList)
                {
                cout<<x.first<<" : ";
                for(auto y: x.second)
                    cout<<y.first<<" ("<<y.second<<"), ";
                cout<<endl;
                }
            }
    };

int main()
    {
    Graph<string, int> g;
    g.addEdge("Putin", "Trump", 2, false);
    g.addEdge("Putin", "Modi", 3, false);
    g.addEdge("Putin", "Pope", 4, false);
    g.addEdge("Modi", "Trump", 5, true);
    g.addEdge("Modi", "Yogi", 6, true);
    g.addEdge("Yogi", "Prabhu", 7, false);
    g.addEdge("Prabhu", "Modi", 1, false);
    g.printAdjList();
    return 0;
    }