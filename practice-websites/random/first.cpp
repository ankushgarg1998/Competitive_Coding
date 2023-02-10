#include<iostream>
using namespace std;

int main()
  {
  int T, N;
  char c;
  cin>>T;
  for(int t=0;t<T;t++)
    {
    cin>>N>>c;
    switch(N)
      {
      case 1: cout<<"1";
              break;
      case 2: if(c=='s')
                cout<<"2";
              else
                cout<<"3";
              break;
      case 3: if(c=='s')
                cout<<"4";
              else if(c=='p')
                cout<<"5";
              else
                cout<<"7";
              break;
      case 4: if(c=='s')
                cout<<"6";
              else if(c=='p')
                cout<<"8";
              else if(c=='d')
                cout<<"10";
              else
                cout<<"13";
              break;
      case 5: if(c=='s')
                cout<<"9";
              else if(c=='p')
                cout<<"11";
              else if(c=='d')
                cout<<"14";
              else
                cout<<"17";
              break;
      case 6: if(c=='s')
                cout<<"12";
              else if(c=='p')
                cout<<"15";
              else if(c=='d')
                cout<<"18";
              else
                cout<<"21";
              break;
      default:if(c=='s')
                cout<<(12+(4*(N-6)));
              else if(c=='p')
                cout<<(15+(4*(N-6)));
              else if(c=='d')
                cout<<(18+(4*(N-6)));
              else
                cout<<(21+(4*(N-6)));
              break;
      }
    cout<<"\n";
    }
  return 0;
  }
