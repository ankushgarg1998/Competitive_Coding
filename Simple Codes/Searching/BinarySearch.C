#include<stdio.h>
#include<conio.h>

int find(int *lis, int size, int element)
	{
	int i, first=0, mid, last=size-1;
	while(last>=first)
		{
		mid = (first+last)/2;
		//printf("First=%d, Mid=%d, Last=%d\n", first, mid, last);
		//printf("First=%d, Mid=%d, Last=%d\n", *(lis+first), *(lis+mid), *(lis+last));
		if(*(lis+mid) == element)
			return (mid+1);
		else if(*(lis+mid) < element)
			first = mid+1;
		else
			last = mid-1;
		}
	return -1;
	}

void main()
{
int i, arr[100], size, element, end=1, pos;
do
	{
	clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&size);
	printf("Enter the elements : \n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Find the element to be searched : ");
	scanf("%d",&element);

	pos = find(arr, size, element);

	if(pos==-1)
		printf("\nThe element %d was not found !",element);
	else
		printf("\nThe element %d was found at position : %d",element, pos);
	printf("\n\nPress 0 to Exit and 1 to Try Again : ");
	scanf("%d",&end);
	}while(end!=0);
}