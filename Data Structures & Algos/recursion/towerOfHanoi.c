#include<stdio.h>

int c=0;
void toh(int, char, char, char);
void main()
  {
  int n;
  printf("Enter No. of disks (to be transferred form A to C) : ");
  scanf("%d", &n);
  toh(n, 'A', 'B', 'C');
  printf("%d", c);
  }

void toh(int n, char beg, char aux, char end)
  {
  if(n>=1)
    {
    ++c;
    toh(n-1, beg, end, aux);
    printf("%c to %c\n",beg, end);
    toh(n-1, aux, beg, end);
    }
  }
