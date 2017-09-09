#include<stdio.h>
#include<string.h>
void permut(char *, int, int);
void swap(char *a, char *b)
  {
  char ch;
  ch=*a;
  *a=*b;
  *b=ch;
  }
int count = 0;
void main()
  {
  int i,n;
  char str[10];
  printf("Enter a string without repetetion :");
  scanf("%s", str);
  printf("%s %d\n\n", str, strlen(str));
  permut(str, 0, strlen(str)-1);
  printf("\n\nCount = %d", count);
  }
void permut(char *s, int i, int n)
  {
  int j;
  if (i==n)
    {
    ++count;
    printf("\n%s", s);
    }
  else
    {
    for(j=i;j<=n;j++)
      {
      swap((s+i), (s+j));
      // printf("%s", s);
      permut(s, i+1, n);
      swap((s+i), (s+j));
      }
    }
  }
