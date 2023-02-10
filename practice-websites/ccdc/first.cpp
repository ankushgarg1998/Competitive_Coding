#include<iostream>
#include<map>
#include<list>
#include<queue>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

template<typename T>
class Graph
    {
    map<T, list<T> > adjList;
    public:
        void addEdge(T u, T v, bool bidir = false)
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

        bool isCycleBFS()
            {
            int src = 1;
            queue<T> q;
            map<T, int> parent;
            map<T, bool> visited;

            // q.push(src);
            // visited[src] = true;
            // parent[src] = src;

            for(auto x: adjList) {
                if(!visited[x.first]) {
                    q.push(x.first);
                    visited[x.first] = true;
                    parent[x.first] = x.first;
                }
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
                }
                return false;
            }
    };

int main()
    {
    Graph<int> g;
    int n, x;
    cin>>n;
    loop(i, 1, n+1) {
        cin>>x;
        g.addEdge(i, x);
    }
    if(g.isCycleBFS()) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
    return 0;
    }