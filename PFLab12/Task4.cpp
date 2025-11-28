#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = (int*)malloc(3*sizeof(int));
	if (ptr == NULL)
	{
		printf("\nMemory Allocaion Failed.");
		return 1;
	}
	for(int i=0; i<3; ++i)
	{
		printf("\nEnter value #%d: ", i+1);
		scanf(" %d", &ptr[i]);
	}
	int arrsize=0;
	printf("\nArray is now full, Enter new bigger size of the array: ");
	scanf("%d", &arrsize);
	
	ptr = (int*)realloc(ptr, arrsize);
	
	int morenum = arrsize-3;
	printf("\nEnter %d more elements.", morenum);
	for(int i=3; i<arrsize; ++i)
	{
		printf("\nEnter value #%d: ", i+1);
		scanf("%d", &ptr[i]);
	}
	printf("\nThe final array is:\n");
	for(int i=0; i<arrsize; ++i)
	{
		printf("\nvalue #%d:  %d", i+1, ptr[i]);
	}
	return 0;
}
