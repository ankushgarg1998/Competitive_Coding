#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

long int gcdExtended(long int a, long int b, long int *x, long int *y);
long int modInverse(long int b, long int m)
{
	long int x, y;
	long int g = gcdExtended(b, m, &x, &y);
	if (g != 1)
		return -1;
	return (x%m + m) % m;
}

long int modDivide(long int a, long int b, long int m)
  {
	a = a % m;
	long int inv = modInverse(b, m);
	return ((inv * a) % m);
  }

long int gcdExtended(long int a, long int b, long int *x, long int *y)
  {
	if (a == 0)
	   {
		 *x = 0, *y = 1;
		 return b;
	   }
	long int x1, y1;
	long int gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
  }

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
                ans = modDivide(A[R], A[L-1], P);
                // ans = ((P+A[R])/A[L-1])%P;
            // cout<<ans<<" ";
            x = (ans+1)%P;
            }
        cout<<x<<"\n";
        }
    return 0;
    }
