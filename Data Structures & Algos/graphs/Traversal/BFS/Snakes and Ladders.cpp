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

        int sssp(T src, T dest)
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
            // for(auto i: adjList)
            //     {
            //     cout<<" Dist of "<<i.first<<" from "<<src<<" is "<<dist[i.first]<<endl;
            //     cout<<" Parent of "<<i.first<<" is "<<parent[i.first]<<"\n\n";
            //     }

            // Print the path
            T temp = dest;
            while(temp != src)
                {
                cout<<temp<<" <-- ";
                temp = parent[temp];
                }
            cout<<src;

            return dist[dest];
            }
    };

int main()
    {
    Graph<int> g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    // Constructing the graph
    for(int u=0; u<=35; u++)
        {
        for(int dice=1; dice<=6; dice++)
            {
            int v = u + dice + board[u+dice];
            g.addEdge(u, v, false);
            }
        }

    cout<<"\nThe shortest dist is "<<g.sssp(0, 36);
    return 0;
    }