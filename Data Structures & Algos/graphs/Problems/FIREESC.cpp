#include<iostream>
#include<map>
#include<list>
#include<vector>
#define test int t; cin>>t; while(t--)
#define mod 1000000007
using namespace std;

class Graph
    {
    map<string, list<string> > adjList;
    map<string, bool> visited;
    public:
    int N;
    int components = 0;
    long long int bla = 1;
        void addEdge(string a, string b)
            {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            }
        long long int dfsHelper(string x)
            {
            visited[x] = true;
            long long int count = 1;
            for(auto y: adjList[x])
                {
                if(!visited[y])
                    count += dfsHelper(y);
                }
            return count;
            }
        void connectedComponents()
            {
            for(auto x: adjList)
                {
                if(!visited[x.first])
                    {
                    bla = max(bla, dfsHelper(x.first));
                    // bla *= dfsHelper(x.first);
                    // bla %= mod;
                    ++components;
                    }
                }
            // If there's still any unconnected vertex left.
            // for(int i=1; i<=N; i++)
            //     {
            //     if(!visited[i])
            //         ++components;
            //     }
            }
    };

int main()
    {
    int N, M;
    string a, b;
    test
        {
        Graph g;
        cin>>M;
        for(int i=0; i<M; i++)
            {
            cin>>a>>b;
            g.addEdge(a, b);
            }
        g.connectedComponents();
        cout<<g.components<<" "<<g.bla<<"\n";
        }
    return 0;
    }