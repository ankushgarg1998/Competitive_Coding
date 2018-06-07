#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
    return a.second < b.second;
    }

int main()
    {
    int t;
    cin>>t;
    int N, L, N_2;
    for(int test=1; test<=t; test++)
        {
        bool arr[260];
        cin>>N>>L;
        vector<int> v(L);
        vector<pair<int, int> > g;
        int ans = 0;
        for(int i=1; i<=N; i++)
            {
            if(((i*100)/(double)N) - ((i*100)/N) >= 0.5)
                arr[i] = true;
            }
        int left = N, j;
        // N_2 = N/2;
        // if(N&1 == 1)
        //     ++N_2;
        for(int i=0; i<L; i++)
            {
            cin>>v[i];
            left -= v[i];
            if(arr[v[i]])
                ans += (0.5 + (v[i]*100)/(double)N);
            else
                {
                for(j=v[i]; !arr[j] && j<=N; ++j);
                // cout<<j<<"\n";
                g.push_back(make_pair(v[i], j-v[i]));
                }
            }
        // cout<<ans<<"lm\n";
        sort(g.begin(), g.end(), comp);
        int minval = 250;
        for(int i=1; i<N; i++)
            {
            if(arr[i])
                {
                minval = i;
                break;
                }
            }
        // cout<<left<<"m\n";
        for(auto el: g)
            {
            if(el.second > minval)
                {
                ans += (0.5 + ((el.first)*100)/(double)N);
                }
            else if(el.second <= left)
                {
                left -= el.second;
                ans += (0.5 + ((el.first + el.second)*100)/(double)N);
                }
            else
                {
                ans += (0.5 + ((el.first)*100)/(double)N);
                }
            }
        while(true)
            {
            if(minval <= left)
                {
                // cout<<ans<<"lm\n";
                left -= minval;
                ans += (0.5 + (minval*100)/(double)N);
                // cout<<ans<<"lm\n";
                }
            else
                {
                ans += (0.5 + (left*100)/(double)N);
                break;
                }
            }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
        }
    return 0;
    }