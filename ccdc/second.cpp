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

        bool isCyclicHelper(T node, map<T, bool> &visited, T parent, T preparent)
            {
            visited[node] = true;
            // cout<<node<<" "<<parent<<" "<<preparent<<"\n";
            for(T neighbor: adjList[node])
                {
                if(!visited[neighbor])
                    {
                    bool cycleDetected = isCyclicHelper(neighbor, visited, node, parent);
                    if(cycleDetected)
                        return true;
                    }
                else if(neighbor != parent && parent != preparent)
                    return true;
                }
            return false;
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
                    bool ans = isCyclicHelper(node, visited, node, node);
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
    int n, x;
    cin>>n;
    loop(i, 1, n+1) {
        cin>>x;
        g.addEdge(i, x);
    }
    // g.printAdjList();
    if(g.isCyclicDFS()) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
    return 0;
    }