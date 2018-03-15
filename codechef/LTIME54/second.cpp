#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
    {
    int t;
    long int X, Y, M, i;
    cin>>t;
    while(t--)
        {
        cin>>M>>X>>Y;
        if(X == 0)
            {
            cout<< (M^(M-1)) <<"\n";
            continue;
            }
        vector<long int> A(M);
        for(i=1; i<=M; i++)
            A[i-1] = i;
        while(M > 2)
            {

            for(auto a:A)
                cout<<a<<" ";
            cout<<"\n";

            vector<long int> eve;
            vector<long int> odd;
            for(i=0; i<M; i+=2)
                eve.push_back(A[i]);
            for(i=1; i<M; i+=2)
                odd.push_back(A[i]);
            eve.erase(eve.begin() + ((M/2)*X/Y));
            odd.erase(odd.begin() + ((M/2)*X/Y));

            for(auto e:eve)
                cout<<e<<" ";
            cout<<"Eve\n";
            for(auto o:odd)
                cout<<o<<" ";
            cout<<"Odd\n";

            A.clear();
            M -= 2;
            A.reserve(M);
            A.insert(A.end(), eve.begin(), eve.end() );
            A.insert(A.end(), odd.begin(), odd.end() );
            // eve.clear();
            // odd.clear();
            }
        cout<< (A[0]^A[1]) <<"\n";
        }
    return 0;
    }
