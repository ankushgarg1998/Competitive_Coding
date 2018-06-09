#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sortbysec(const pair<char, int> &a, const pair<char, int> &b)
    {
    if(a.second > b.second)
        return true;
    else
        return false;
    }

int main()
    {
    int t, N, x;
    cin>>t;
    for(int test=1; test<=t; test++)
        {
        vector<pair<char, int> > v;
        cin>>N;
        for(int i=0; i<N; i++)
            {
            cin>>x;
            v.push_back(make_pair(65+i, x));
            }
        cout<<"Case #"<<test<<": ";
        while(N)
            {
            sort(v.begin(), v.end(), sortbysec);

            if(v[0].second > v[1].second)
                {
                if(v[0].second == 2 && N == 2)
                    {
                    cout<<v[0].first<<v[1].first<<" "<<v[0].first;
                    break;
                    }
                cout<<v[0].first<<v[0].first<<" ";
                v[0].second -= 2;
                }
            else
                {
                if(v[0].second == 1 && N == 3)
                    {
                    cout<<v[0].first<<" "<<v[1].first<<v[2].first;
                    break;
                    }
                cout<<v[0].first<<v[1].first<<" ";
                --v[0].second;
                --v[1].second;
                }
            if(v[0].second == 0)
                --N;
            if(v[1].second == 0)
                --N;
            }
        cout<<"\n";
        }
    return 0;
    }