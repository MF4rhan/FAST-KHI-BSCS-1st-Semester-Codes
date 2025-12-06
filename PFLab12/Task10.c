#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* array = (int*)malloc(2*sizeof(int));
	if (array == NULL)
	{
		printf("\nMalloc Failed.");
		return 1;
	}
	for (int i = 0; i < 2; ++i)
	{
		printf("\nEnter Integer#%d of the array: ", i+1);
		scanf("%d", &array[i]);
	}

int* temp = (int*)realloc(array, 4*sizeof(int));
if (temp == NULL)
{
	printf("\nRealloc Failed.");
	return 1;
}

free(array);

for (int i = 0; i < 4; ++i)
	{
		printf("\nInteger#%d of the array: %d", i+1, array[i]);
	}

free(temp);
return 0;
}