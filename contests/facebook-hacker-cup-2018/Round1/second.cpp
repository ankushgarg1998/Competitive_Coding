#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
using namespace std;

class Graph {
    int N;
    map<int, vector<int> > adjList;

    public:
        vector<int> ids;
        Graph(int n) {
            N = n;
            loop(i, 1, n+1) {
                vector<int> v;
                adjList.insert(make_pair(i, v));
            }
            ids = vector<int>(n+1, 0);
        }

        void addEdge(int u, int v) {
            if(u == v)
                return;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printAdjList() {
            for(auto x: adjList) {
                cout<<x.first<<": ";
                for(auto y: x.second) {
                    cout<<y<<" ";
                }
                cout<<'\n';
            }
        }

        void dfsHelper(int x, unordered_map<int, bool> &visited, int id) {
            visited[x] = true;
            ids[x] = id;
            for(auto y: adjList[x]) {
                if(!visited[y]) {
                    dfsHelper(y, visited, id);
                }
            }
        }

        int connectedComponents() {
            unordered_map<int, bool> visited;
            int components = 0;
            
            for(auto x: adjList) {
                if(!visited[x.first]) {
                    ++components;
                    dfsHelper(x.first, visited, components);
                }
            }
            return components;
        }
};

void preorder(unordered_map<int, pair<int, int> > &tree, vector<int> &v, int node) {
    if(node == 0) {
        return;
    }
    v.push_back(node);
    preorder(tree, v, tree[node].first);
    preorder(tree, v, tree[node].second);
}

void postorder(unordered_map<int, pair<int, int> > &tree, vector<int> &v, int node) {
    if(node == 0) {
        return;
    }
    postorder(tree, v, tree[node].first);
    postorder(tree, v, tree[node].second);
    v.push_back(node);
}

int main() {
    int t, n, k, l, r;
    cin>>t;
    loop(test, 1, t+1) {
        cin>>n>>k;
        unordered_map<int, pair<int, int> > tree;
        loop(i, 1, n+1) {
            cin>>l>>r;
            tree.insert(make_pair(i, make_pair(l, r)));
        }

        vector<int> v_pre, v_post;
        preorder(tree, v_pre, 1);
        postorder(tree, v_post, 1);

        // for(auto x: v_pre)
        //     cout<<x<<" ";
        // cout<<"\n";
        // for(auto x: v_post)
        //     cout<<x<<" ";

        Graph g(n);
        loop(i, 0, n) {
            g.addEdge(v_pre[i], v_post[i]);
        }
        // g.printAdjList();

        int components = g.connectedComponents();
        cout<<"Case #"<<test<<": ";
        if(components>=k) {
            loop(i, 1, n+1) {
                if(g.ids[i] > k)
                    g.ids[i] = k;
                cout<<g.ids[i]<<" ";
            }
        }
        else
            cout<<"Impossible";
        cout<<"\n";
    }
    return 0;
}