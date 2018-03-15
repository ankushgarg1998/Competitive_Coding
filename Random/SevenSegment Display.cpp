//SevenSegment Display
//Problem : https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/jarvis-and-seven-segments-1/


#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int countbulb(int);

int main()
{
    int t,n,line[20];
    cin>>t;
    for(int h=0;h<t;h++)
    {
    cin>>n;
    int A[100000][2];

    for (int i=0;i<n;i++)
        {
        cin>>A[i][0];
        }

    for (int j=0;j<n;j++)
        {
        A[j][1]=countbulb(A[j][0]);
        }

    int temp,ans;
    ans=A[0][0];
    temp=A[0][1];
    for(int k=1;k<n;k++)
        {
        if(A[k][1]<temp)
            {
            temp=A[k][1];
            ans=A[k][0];
            }
        }
    line[h]=ans;
    }
    for(int q=0;q<t;q++)
      cout<<line[q]<<endl;
    return 0;
}



int countbulb(int x)
  {
  int count=0;
  char s[10];
  sprintf (s, "%d",x);
  for(int i=0;i<(strlen(s));i++)
    {
    if(s[i]=='1')
      count+=2;
    else if(s[i]=='2' || s[i]=='3' || s[i]=='5')
      count+=5;
    else if(s[i]=='4')
      count+=4;
    else if(s[i]=='6' || s[i]=='9' || s[i]=='0')
      count+=6;
    else if(s[i]=='7')
      count+=3;
    else if(s[i]=='8')
      count+=7;
    else
      cout<<"Error";
    }
  return count;
  }
