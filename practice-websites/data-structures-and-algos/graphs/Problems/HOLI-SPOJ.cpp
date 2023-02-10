#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph
    {
    map<T, list<pair<T, int> > > adjList;
    vector<vector<int> > edgeList;
    map<T, int> count;
    public:
        int N;
        void addEdge(T u, T v, int weight, bool bidir=true)
            {
            adjList[u].push_back(make_pair(v, weight));
            if(bidir)
                adjList[v].push_back(make_pair(u, weight));
            
            // Making Edge List
            vector<int> temp;
            temp.push_back(u);
            temp.push_back(v);
            temp.push_back(weight);
            edgeList.push_back(temp);
            }
    
        void printAdjList()
            {
            for(auto u: adjList)
                {
                cout<<"\n"<<u.first<<" -> ";
                for(auto v: u.second)
                    cout<<"("<<v.first<<", "<<v.second<<") ";
                }
            }

        int dfsHelper(T src, unordered_map<T, bool> &visited)
            {
            visited[src] = true;
            count[src] = 1;
            // cout<<src<<" ";
            for(auto u: adjList[src])
                {
                if(!visited[u.first])
                    count[src] += dfsHelper(u.first, visited);
                }
            // cout<<src<<" ";
            return count[src];
            }
        
        void dfs(T src)
            {
            unordered_map<T, bool> visited;
            int a = dfsHelper(src, visited);
            }

        long int edgePlay()
            {
            long int ans = 0;
            for(auto edge: edgeList)
                {
                int mini = min(count[edge[0]], count[edge[1]]);
                int maxi = max(count[edge[0]], count[edge[1]]); 
                ans += 2*min((N-mini), mini)*edge[2];
                }
            return ans;
            }
    };

int main()
    {
    int u, v, w, test;
    cin>>test;
    for(int t=1; t<=test; t++)
        {
        Graph<int> g;
        cin>>g.N;
        for(int i=0; i<(g.N)-1; i++)
            {
            cin>>u>>v>>w;
            g.addEdge(u, v, w);
            }
        // g.printAdjList();
        g.dfs(1);
        cout<<"Case: #"<<t<<": "<<g.edgePlay()<<"\n";
        }
    return 0;
    }