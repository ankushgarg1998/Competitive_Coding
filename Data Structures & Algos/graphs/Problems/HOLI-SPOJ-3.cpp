#include<bits/stdc++.h>

using namespace std;

class Graph
{
map<int, list<pair<int, int> > > adjList;
vector<int> counti = vector<int>(100010);
vector<bool> visited = vector<bool>(100010);

public:
    int N;
    long long int ans = 0;

    void addEdge(int u, int v, int weight)
        {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
        }

    int dfsHelper(int src)
        {
        visited[src] = true;
        counti[src] = 0;
        int jeremy;
        for(auto u: adjList[src])
            {
            if(!visited[u.first])
                {
                
                jeremy = dfsHelper(u.first);
                counti[src] += jeremy;
                ans += 2*u.second*min(jeremy, N-jeremy);
                }
            }
        counti[src] += 1;
        return counti[src];
        }
};

int main()
{
int u, v, w, test;
cin>>test;
for(int t=1; t<=test; t++)
    {
    Graph g;
    cin>>g.N;
    for(int i=1; i<(g.N); i++)
        {
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
        }
    g.dfsHelper(1);
    cout<<"Case: #"<<t<<": "<<g.ans<<"\n";
    }
return 0;
}