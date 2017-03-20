//PassWord Checker
#include<iostream>
#include<string>
using namespace std;
int main()
  {
  string stri;
  int cap=0,small=0,integ=0,sp=0;
  getline(cin,stri);
  cout<<stri;
  int len = stri.size();
  for (int i=0;i<len;i++)
    {
    char ch = stri[i];
    if (ch>=65 && ch<=90)
      cap++;
    else if (ch>=97 && ch<=122)
      small++;
    else if (ch>=48 && ch<=57)
      integ++;
    else
      sp++;
    }
  /*cout<<"\ncap : "<<cap;
  cout<<"\nsmall : "<<small;
  cout<<"\ninteger : "<<integ;
  cout<<"\nsp : "<<sp;*/
  if(cap==0)
    cout<<"\nEnter atleast one Capital Letter";
  if(small==0)
    cout<<"\nEnter atleast one Small Letter";
  if(integ==0)
    cout<<"\nEnter atleast one Integer";
  if(sp==0)
    cout<<"\nEnter atleast one Special Character";
  if(cap!=0 && small!=0 && integ!=0 && sp!=0)
    cout<<"\n\nPerfectly Strong PassWord : "<<stri;

  cin.get();
  return 0;
  }
