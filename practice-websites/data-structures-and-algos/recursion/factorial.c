#include<stdio.h>

int fac(int);
void main()
  {
  int n;
  printf("Find factoial of : ");
  scanf("%d", &n);
  printf("%d", fac(n));
  }

int fac(int n)
  {
  if(n==1)
    return 1;
  else
    return n*fac(n-1);
  }
