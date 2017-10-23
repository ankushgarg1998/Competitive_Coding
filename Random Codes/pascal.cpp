#include<iostream>
using namespace std;
int main()
  {
  int i, j, k, n, a[15][15];
  cin>>n;
  for(i=1; i<=n; i++)
    {
    k = (3*n)-(2*i);
    while(k--)
      cout<<" ";
    for(j=1; j<=i; j++)
      {
      if(j == 1)
        {
        a[i][j] = 1;
        cout<<"1   ";
        }
      else if(i == j)
        {
        a[i][j] = 1;
        cout<<"1";
        }
      else
        {
        a[i][j] = a[i-1][j-1] + a[i-1][j];
        cout<<a[i][j]<<"   ";
        }
      }
    cout<<"\n";
    }
  return 0;
  }
