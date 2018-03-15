#include <iostream>
#include<vector>
using namespace std;
int main()
    {
    int t;
    long int N, Q, i;
    long long int ans;
    cin>>t;
    while(t--)
        {
        cin>>N>>Q;
        ans = 1;
        vector<long int> D(N);
        vector<long int> X(Q);
        for(i=0; i<N; i++)
            {
            cin>>D[i];
            if(ans*D[i] <= 1000000000)
                ans *= D[i];
            else
            	ans = 1000000001;
            }
        for(i=0; i<Q; i++)
            {
            cin>>X[i];
            cout<<X[i]/ans<<" ";
            }
        cout<<"\n";
        }
    return 0;
    }
