#include<iostream>
using namespace std;

int main()
  {
  int T, N;
  cin>>T;
  for(int t=0;t<T;t++)
    {
    cin>>N;
    long long int a[1000], b[1000], maxa, maxb;
    int i, counta, countb;
    for(i=0; i<N; i++)
      cin>>a[i];
    for(i=0; i<N; i++)
      cin>>b[i];
    maxa = a[0];
    counta = 1;
    maxb = b[0];
    countb = 1;
    for(i=1; i<N; i++)
      {
      if(a[i] > maxa)
        {
        maxa = a[i];
        counta = 1;
        }
      else if(a[i] == maxa)
        ++counta;

      if(b[i] > maxb)
        {
        maxb = b[i];
        countb = 1;
        }
      else if(b[i] == maxb)
        ++countb;
      }    
    cout<<(counta*countb)<<"\n";
    }
    return 0;
  }
