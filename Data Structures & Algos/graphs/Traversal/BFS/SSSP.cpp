#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
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

        void sssp(T src)
            {
            queue<T> q;
            map<T, int> dist;
            map<T, T> parent;

            // for(auto i: adjList)
            //     dist[i.first] = INT_MAX;

            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            while(!q.empty())
                {
                T node = q.front();
                // cout<<node<<" ";

            for(T neighbor : adjList[node])
                    {
                    if(dist.find(neighbor) == dist.end())
                        {
                        q.push(neighbor);
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        }
                    }

                q.pop();
                }
            // Print the distances to other nodes
            for(auto i: adjList)
                {
                cout<<" Dist of "<<i.first<<" from "<<src<<" is "<<dist[i.first]<<endl;
                cout<<" Parent of "<<i.first<<" is "<<parent[i.first]<<"\n\n";
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
    g.sssp("Modi");
    // return 0;
    }