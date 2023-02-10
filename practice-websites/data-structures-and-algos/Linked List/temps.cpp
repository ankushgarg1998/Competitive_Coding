#include<iostream>
#define max 1000
using namespace std;

int main()
  {
  int a[max], b[max], m, n, i;
  char stra[max], strb[max];

  cout<<"Number of Digits in First Number : ";
  cin>>m;
  cout<<"Enter First Number : ";
  for(i=0; i<m; i++)
    cin>>stra[i];
  cout<<"\nNumber of digits in Second Number : ";
  cin>>n;
  cout<<"Enter second Number : ";
  for(i=0; i<n; i++)
    cin>>strb[i];

  for(i=0; i<m; i++)
    a[i] = stra[m-i-1] - '0';
  for(i=0; i<n; i++)
    b[i] = strb[n-i-1] - '0';

  for(i=0; i<m; i++)
    cout<<a[i];
  cout<<endl;
  for(i=0; i<n; i++)
    cout<<b[i];


  return 0;
  }

11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
