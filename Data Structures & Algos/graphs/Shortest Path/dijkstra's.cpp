#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
    {
    unordered_map<T, list<pair<T, int> > > m;
    
    public:
        void addEdge(T u, T v, int weight, bool bidir=true)
            {
            m[u].push_back(make_pair(v, weight));
            if(bidir)
                m[v].push_back(make_pair(u, weight));
            }
     
        void printAdj()
            {
            for(auto u: m)
                {
                cout<<"\n"<<u.first<<" -> ";
                for(auto v: u.second)
                    cout<<"("<<v.first<<", "<<v.second<<") ";
                }
            cout<<endl;
            }
     
        void dijkstras(T src)
            {
            unordered_map<T, int> dist;
            for(auto u: m)
                dist[u.first] = INT_MAX;

            // Set to find out the node with the minimum distance
            set<pair<int, T> > s;
            dist[src] = 0;
            s.insert(make_pair(0, src));

            while(!s.empty())
                {
                auto p = *(s.begin());
                T node = p.second;

                int nodeDist = p.first;
                s.erase(s.begin());

                // Iterate over neighbors of the current node
                for(auto childPair: m[node])
                    {
                    if(nodeDist+childPair.second < dist[childPair.first])
                        {
                        // In a set updation of a particular element is not possible.
                        // So we'll have to remove the old pair and add a new pair to simulate updations.
                        T dest = childPair.first;
                        auto f = s.find(make_pair(dist[dest], dest));
                        if(f != s.end())
                            s.erase(f);
                        dist[dest] = nodeDist + childPair.second;
                        s.insert(make_pair(dist[dest], dest));
                        }
                    }
                }

            for(auto d: dist)
                cout<<"\n"<<d.first<<" : "<<d.second;
            }
    };

int main()
    {
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.printAdj();
    g.dijkstras(1);
    }