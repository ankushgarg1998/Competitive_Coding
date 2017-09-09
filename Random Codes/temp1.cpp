#include<iostream>
using namespace std;

int main()
  {
  unsigned long long int n, i, m = 1000000007;
  int T;
  cin>>T;
  for(int t=0; t<T; t++)
  {
    cin>>n;
    i=1;
    switch(n%4)
      {
      case 0: i = (i*(n/4)) % m;
              i = (i*(n-1)) % m;
              i = (i*((n-2)/2)) % m;
              i = (i*(n-3)) % m;
              break;
      case 1: i = (i*n) % m;
              i = (i*((n-1)/4)) % m;
              i = (i*(n-2)) % m;
              i = (i*((n-3)/2)) % m;
              break;
      case 2: i = (i*(n/2)) % m;
              i = (i*(n-1)) % m;
              i = (i*((n-2)/4)) % m;
              i = (i*(n-3)) % m;
              break;
      case 3: i = (i*(n)) % m;
              i = (i*((n-1)/2)) % m;
              i = (i*(n-2)) % m;
              i = (i*((n-3)/4)) % m;
              break;

      }
  cout<<i<<"\n";
  }
  return 0;
  }
