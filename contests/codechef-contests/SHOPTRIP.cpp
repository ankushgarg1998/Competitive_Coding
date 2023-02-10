#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

int t, n, k;
long double dist[40][40];
string ingre[40];
int ingredients[40];
int ALL_FOUND;
long double dp[4100][40];

long double f(int ingre_mask, int current_shop, string visited)
    {
    if(ingre_mask == ALL_FOUND)
        return dist[current_shop][0];

    if(dp[ingre_mask][current_shop] != -1)
        return dp[ingre_mask][current_shop];
    
    long double ans = 16000000;
    for(int i=1; i<=n ; i++)
        {
        if(visited[i] == '0')
            {
            visited[i] = '1';
            ans = min(ans, dist[current_shop][i] + f(ingre_mask | ingredients[i], i, visited));
            visited[i] = '0';
            }
        }
    return dp[ingre_mask][current_shop] = ans;
    }

int main()
    {
    cin>>t;
    while(t--)
        {
        cin>>n>>k;
        ALL_FOUND = (1<<k)-1;
        string visited = "0";

        for(int i=1; i<=n; i++)
            visited += "0";

        for(int i=0; i<=4096; i++)
            {
            for(int j=0; j<=36; j++)
                dp[i][j] = -1;
            }

        vector<pair<int, int> > xy(n+1);
        xy[0].first = 0;
        xy[0].second = 0;
        for(int i=1; i<=n; i++)
            cin>>xy[i].first>>xy[i].second;

        int ans = 0;
        ingredients[0] = 0;

        for(int i=1; i<=n; i++)
            {
            cin>>ingre[i];
            ingredients[i] = stoi(ingre[i], nullptr, 2);
            ans = ans | ingredients[i];
            }

        // Checking if it is even possible
        if(ans != ALL_FOUND)
            {
            cout<<"-1\n";
            continue;
            }

        // Created the Weighted Adjacency Matrix
        for(int i=0; i<=n; i++)
            {
            for(int j=0; j<=n; j++)
                {
                dist[i][j] = sqrt(pow(xy[j].second-xy[i].second, 2) + pow(xy[j].first-xy[i].first, 2));
                // cout<<dist[i][j]<<"\t";
                }
            // cout<<"\n";
            }

        cout<<fixed<<setprecision(10)<<f(0, 0, visited)<<"\n";
        }
    return 0;
    }