#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    long long int a[100001], i, j, N, K, yet_max, curr_max, sum_all;
    test
        {
        cin>>N>>K;
        for(i=0; i<N; i++)
            cin>>a[i];
        yet_max = a[0];
        curr_max = a[0];
        sum_all = a[0];
        for(i=1; i<N; i++)
            {
            sum_all += a[i];
            curr_max = max(a[i], curr_max+a[i]);
            yet_max = max(yet_max, curr_max);
            }
        // for(j=1; j<K; j++)
        //     {
        //     for(i=0; i<N; i++)
        //         {
        //         curr_max = max(a[i], curr_max+a[i]);
        //         yet_max = max(yet_max, curr_max);
        //         }
        //     }
        if(sum_all > 0)
            cout<<(((K-1)*sum_all) + yet_max);
        else
            {
            if(K>1)
                {
                for(i=0; i<N; i++)
                    {
                    curr_max = max(a[i], curr_max+a[i]);
                    yet_max = max(yet_max, curr_max);
                    }
                }
            cout<<yet_max;
            }
        cout<<"\n";
        }
    return 0;
    }
