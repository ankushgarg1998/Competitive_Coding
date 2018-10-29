#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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

        void bfs(T src)
            {
            queue<T> q;
            map<T, bool> visited;

            q.push(src);
            visited[src] = true;

            while(!q.empty())
                {
                T node = q.front();
                cout<<node<<" ";

                for(T neighbor : adjList[node])
                    {
                    if(!visited[neighbor])
                        {
                        q.push(neighbor);
                        visited[neighbor] = true;
                        }
                    }

                q.pop();
                }
            }
    };

int main() {
    Graph<int> g;
    return 0;
}