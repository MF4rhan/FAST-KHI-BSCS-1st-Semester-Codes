#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* array = (int*)malloc(4);
	if (array==NULL)
	{
		printf("\nMalloc Failed.");
		return 1;
	}
	for (int i = 0; i < 4; ++i)
	{
		printf("\nEnter Integer#%d of the array: ", i+1);
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		printf("\nInteger#%d of the array: %d", i+1, array[i]);
	}

	free(array);
	return 0;
}