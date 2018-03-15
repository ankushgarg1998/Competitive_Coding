#include<iostream>
#include<vector>
using namespace std;
int main()
    {
    long int N, Q, L, R, i, a, b, c, beg, end, now, count;
    cin>>N>>Q>>L>>R;
    vector<long int> v(N+1, 0);
    // long int arr[] = {2, 4, 9, 11, 12, 3, 15, 6, 9, 22, 10, 10, 10};
    // vector<long int> v(arr, arr+13);
    while(Q--)
        {
        cin>>a>>b>>c;
        if(a==1)
            v[b] = c;
        else
            {
            beg = b;
            count = 0;
            for(i=b; i<=c; i++)
                {
                if(v[i]<L)
                    continue;
                if(v[i]<=R)
                    {
                    now = i;
                    while(i<=c && v[i]<=R)
                        ++i;
                    end = --i;
                    count += ((now-beg+1)*(end-now+1));
                    // cout<<"count : "<<count;
                    beg = now+1;
                    i = now;
                    }
                else
                    beg = i+1;
                }
            cout<<count<<"\n";
            }
        }
    }
