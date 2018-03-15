#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;
string l, s;
int lsize, ssize, ls[5010][5010];
int rec(int li, int si)
    {
    if(si >= ssize || li >= lsize)
        {
        ls[li][si] = 0;
        return 0;
        }
    int ans = -1;
    for(int i=li; i<lsize; i++)
        {
        if(l[i] == s[si])
            {
            if(ls[i+1][si+1] == -2)
                ls[i+1][si+1] = rec(i+1, si+1);
            ans = max(ans, 1+ls[i+1][si+1]);
            break;
            }
        }
    if(ls[li][si+1] == -2)
        ls[li][si+1] = rec(li, si+1);
    ls[li][si] = max(ans, ls[li][si+1]);
    return ls[li][si];
    }

int main()
    {
    int N, M, i, j, Asize, Bsize;
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
        Asize = A.size();
        Bsize = B.size();
        if(Asize > Bsize)
            {
            l = A;
            lsize = Asize;
            s = B;
            ssize = Bsize;
            }
        else
            {
            l = B;
            lsize = Bsize;
            s = A;
            ssize = Asize;
            }

        for(i=0; i<=lsize; i++)
            {
            for(j=0; j<=ssize; j++)
                ls[i][j] = -2;
            }
        cout<<lsize+ssize-rec(0, 0)<<"\n";
        }
    return 0;
    }
