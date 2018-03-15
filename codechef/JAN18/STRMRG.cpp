#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;
string l, s;
int lsize, ssize;
int rec(int li, int si)
    {
    if(si >= ssize || li >= lsize)
        return 0;
    int ans = -1;
    for(int i=li; i<l.size(); i++)
        {
        if(l[i] == s[si])
            {
            ans = max(ans, 1+rec(i+1, si+1));
            }
        }
    return max(ans, rec(li, si+1));
    }

int main()
    {
    int N, M, i;
    char prev;
    string An, Bm, A, B;
    test
        {
        cin>>N>>M;
        cin>>An;
        cin>>Bm;
        A = An[0];
        B = Bm[0];
        prev = An[0];
        for(i=1; i<N; i++)
            {
            if(An[i] != prev)
                A += An[i];
            prev = An[i];
            }
        prev = Bm[0];
        for(i=1; i<M; i++)
            {
            if(Bm[i] != prev)
                B += Bm[i];
            prev = Bm[i];
            }
        if(A.size() > B.size())
            {
            l = A;
            s = B;
            }
        else
            {
            l = B;
            s = A;
            }
        lsize = l.size();
        ssize = s.size();

        cout<<lsize+ssize-rec(0, 0)<<"\n";
        }
    return 0;
    }
