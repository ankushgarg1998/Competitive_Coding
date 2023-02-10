#include<iostream>
#include<map>
using namespace std;
int main()
    {
    long int n, q, x, y, k, i, living;
    cin>>n;
    living = n;
    map<long int, long int> v;
    for(i=0; i<n; i++)
        {
        cin>>x;
        v[i] = x;
        }
    cin>>q;
    while(q--)
        {
        cin>>x>>y;
        map<long int, long int>::iterator it;
        for(it=v.begin(); it!=v.end(); ++it)
            {
            if(((it->first) & x) == (it->first))
                {
                it->second -= y;
                if(it->second <= 0)
                    {
                    v.erase(it);
                    --living;
                    }
                }
            }

        for(it=v.begin(); it!=v.end(); ++it)
            cout<<it->first<<" - "<< it->second <<" ";
        cout<<living<<"\n";
        }
    return 0;
    }
