#include<iostream>
using namespace std;

int main()
  {
  int T;
  cin>>T;
  for(int t=0;t<T;t++)
    {
    char a[200001], in;
    int i=0;
    cin>>in;
    while(in != '\n')
      {
      a[i] = in;
      ++i;
      in = cin.get();
      }
    int size = i, count=0, poi=0, x;
    for(x=1;;x++)
      {
      ++count;
      poi = (poi+x)%size;
      int isequal=1, z, y;
      for(z=0,y=poi;z<size;z++,y++)
        {
        if(y == size)
          y=0;
        if(a[z] != a[y])
          {
          isequal = 0;
          break;
          }
        }
      if(isequal == 1)
        {
        cout<<count<<"\n";
        break;
        }
      }
    }
  return 0;
  }
