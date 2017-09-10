//GCC compiler ke liye banaya hai. Won't work in TURBO.
//The algo apparently has no limit to number of max digits that can be multiplied. Only limits are provided by your hardware.
//For now the max number of digits is set as 1000;
#include<iostream>
#define max 1000
using namespace std;

int main()
{
  //VARIABLES
  int i, j, k, carry[501]={0}, mul[200][500], sol[500];
  int a[max], b[max], m, n;
  char stra[max], strb[max];

  //INPUTTING
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

  //CALCULATION : Multiplication
  for(i=0; i<m; i++)
    {
    k = 0;
    while(k < i)
      {
      mul[i][k] = 0;
      ++k;
      }
    for(j=0; j<n; j++,++k)
      {
      mul[i][k] = (b[j]*a[i]) + carry[j];
      carry[j+1] = mul[i][k]/10;
      mul[i][k] = mul[i][k]%10;
      }
    mul[i][k] = carry[j];
    carry[0] = 0;
    }

  // CALCULATION : Addition
  for(i=0; i<=k; i++)
    {
    sol[i] = 0;
    for(j=0; j<m; j++)
      {
      sol[i] += mul[j][i];
      }
    sol[i] += carry[i];
    carry[i+1] = sol[i]/10;
    sol[i] = sol[i]%10;
    }

  // PRINTING
  for(i=k ;i>=0; i--)
    cout<<sol[i];
  return 0;
}
