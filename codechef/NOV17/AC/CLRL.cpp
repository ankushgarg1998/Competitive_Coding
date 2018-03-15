#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
    {
    int t;
    long int N, R, i, min, max, recent;
    cin>>t;
    while(t--)
        {
        min = 0; max = INT_MAX;
        cin>>N>>R;
        vector<long int> v(N);
        for(i=0; i<N; i++)
            cin>>v[i];
        if(N <= 2)
            cout<<"YES\n";
        else
            {
            if(v[0] < v[1])
                {
                min = v[0];
                recent = v[1];
                }
            else
                {
                max = v[0];
                recent = v[1];
                }
            for(i=2; i<N; i++)
                {
                // cout<<min<<" "<<recent<<" "<<max<<" "<<v[i]<<"\n";
                if(v[i] > max)
                    {
                    cout<<"NO\n";
                    break;
                    }
                else if(v[i] < min)
                    {
                    cout<<"NO\n";
                    break;
                    }
                else
                    {
                    if(v[i] > recent)
                        {
                        min = recent;
                        recent = v[i];
                        }
                    else
                        {
                        max = recent;
                        recent = v[i];
                        }
                    }
                }
            if(i == N)
                cout<<"YES\n";
            }
        }
    return 0;
    }
