#include<stdio.h>
#include<conio.h>

void main()
	{
	struct matrix
	{
	int row;
	int column;
	int val;
	}  ;
	int i, j, k, n, x[10][10], rows, columns;
	struct matrix mat[10];
	clrscr();
	printf("Enter Rows : ");
	scanf("%d", &rows);
	printf("Enter Columns : ");
	scanf("%d", &columns);
	printf("\n\nStart Entering elements \n");
	for(i=0;i<rows;i++)
		{
		for(j=0;j<columns;j++)
			{
			scanf("%d", &x[i][j]);
			}
		}
	clrscr();
	printf("The Matrix you entered : \n\n");
	for(i=0;i<rows;i++)
		{
		for(j=0;j<columns;j++)
			{
			printf("%d\t", x[i][j]);
			}
		printf("\n");
		}

	k=0;
	for(i=0;i<rows;i++)
		{
		for(j=0;j<columns;j++)
			{
			if(x[i][j]!=0)
				{
				mat[k].row=i;
				mat[k].column=j;
				mat[k].val=x[i][j];
				++k;
				}
			}
		}
	n=k;
	for(k=0;k<n;k++)
		{
		printf("\nMatrix[%d] at (%d,%d) = %d", k, mat[k].row, mat[k].column, mat[k].val);
		}
	getch();
	}
