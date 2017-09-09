#include <iostream>
using namespace std;
void func()
  {}
int main()
  {
  int T;
  cin>>T;
  while(T--)
    {
    unsigned long long int n, m, a[100001][4], i, j, jmax, arr[100001], c;
    int check;
    cin>>n>>m;
    for(i=1; i<=m; i++)
      {
      cin>>a[i][0]>>a[i][1]>>a[i][2];
      a[i][3] = 1;
      }
    // do
    //   {
    //   check = 0;
      for(i=m; i>0; i--)
        {
        if(a[i][0] == 2)
          {
          // check = 1;
          c = a[i][3];
          a[i][3] = 0;
          jmax = a[i][2];
          for(j=a[i][1]; j<=jmax; j++)
            {
            a[j][3] += c;
            a[j][3] %= 1000000007;
            }
          }
        }
      // }while(check == 1);

    for(i=1; i<=n; i++)
      arr[i]=0;
    for(i=1; i<=m; i++)
      {
      if(a[i][0] == 1)
        {
        c = a[i][3];
        jmax = a[i][2];
        for(j=a[i][1]; j<=jmax; j++)
          arr[j] += c;
        }
      }
    for(i=1; i<=n; i++)
      cout<<arr[i]<<" ";
    cout<<"\n";
    }
  }
