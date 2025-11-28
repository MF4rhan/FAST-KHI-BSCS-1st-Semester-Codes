#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = (int*)malloc(5*sizeof(int));
	if (ptr == NULL)
	{
		printf("\nMemory Allocaion Failed.");
		return 1;
	}
	for (int i=0; i<5; ++i)
	{
		ptr[i]=i+1;
	}
	for (int i=0; i<6; ++i)
	{
		printf("\n%d", ptr[i]);
	}
	return 0;
}
