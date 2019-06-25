#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
    {
    int t;
    cin>>t;
    long int N, L, N_2;
    for(int test=1; test<=t; t++)
        {
        cin>>N>>L;
        long int left = N;
        N_2 = N/2;
        if(N&1 == 1)
            ++N_2;
        cout<<N_2<<"yo\n";
        int ans = 0;
        vector<long int> v(L), g;

        for(int i=0; i<L; i++)
            {
            cin>>v[i];
            left -= v[i];
            ans += (int)(0.5 + ((v[i]*100)/(long double)N));
            cout<<ans<<"-";
            v[i] = v[i]%N;
            cout<<v[i]<<" ";
            if(v[i] < N_2)
                cout<<v[i]<<" ";
                g.push_back(v[i]);
            }
        cout<<"\n";
        sort(g.rbegin(), g.rend());
        for(long int x: g)
            {
            long int jerry = N_2 - x;
            if(left >= jerry)
                {
                left -= jerry;
                ++ans;
                }
            else
                break;
            }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
        while(left>0)
            {
            if(left >= N_2)
            ans += (int)(0.5 + ((N_2*100)/(long double)N));
            
            }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
        }
    return 0;
    }