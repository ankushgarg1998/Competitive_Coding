#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
    {
    int t;
    long int N, Q, P, i, j, a, b, by64, x, L, R, ans, prev;
    vector<long int> A, B;
    cin>>t;
    while(t--)
        {
        A.clear();
        B.clear();
        cin>>N>>P>>Q;
        for(i=0, prev=1; i<N; i++)
            {
            cin>>a;
            prev = (a*prev)%P;
            A.push_back(prev);
            }
        for(i=0; i<((Q/64)+2); i++)
            {
            cin>>b;
            B.push_back(b%N);
            }
        x = 0;
        for(i=0; i<Q; i++)
            {
            // cout<<"\nx : "<<x<<"\n";
            if(i%64 == 0)
                {
                by64 = i/64;
                L = (B[by64] + x)%N;
                R = (B[by64+1]+x)%N;
                }
            else
                {
                L = (L+x)%N;
                R = (R+x)%N;
                }
            if(L>R)
                swap(L, R);
            // cout<<"L : "<<L<<" R : "<<R<<"\n";
            if(L==0)
                ans = A[R];
            else
                ans = ((P+A[R])/A[L-1])%P;
            // cout<<ans<<" ";
            x = (ans+1)%P;
            }
        cout<<x<<"\n";
        }
    return 0;
    }
