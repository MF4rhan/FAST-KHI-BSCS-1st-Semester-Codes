#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("\nEnter the number of elements to store in dynamic array: ");
	scanf("%d", &n);
	int* array = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		printf("\nEnter Element at index %d: ", i);
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("\nElement at index %d is %d", i, array[i]);

	}

	free(array);
	array = NULL;
	return 0;
}