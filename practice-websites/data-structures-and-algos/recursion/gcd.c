#include<stdio.h>

int gcd(int a, int b)
  {
  // if (a==b)
  //   return a;
  if (a==0)
    return b;
  else if (b==0)
    return a;
  else if (a>b)
    gcd(b,a%b);
  else
    gcd(a,b%a);
  }

void main()
  {
  int a, b;
  printf("Enter two nubers : ");
  scanf("%d%d", &a, &b);
  printf("\nGCD of %d and %d is %d\n", a, b, gcd(a,b));
  }
