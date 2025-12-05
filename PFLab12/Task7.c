#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr = (int*)malloc(5 * sizeof(int));
	if (ptr==NULL)
	{
		printf("\nInitial Malloc Failed.\n");
		return 1;
	}
	for (int i = 0; i < 5; ++i)
	{
		ptr[i] = i;
	}
	int *ptr2 = (int*)realloc(NULL, 5*sizeof(int));
	if (ptr2==NULL)
	{
		printf("\nRealloc Failed.\n");
		free(ptr);
		return 1;
	}
	printf("The 'Resized' memory address is: %d", ptr2);

	if (ptr!=ptr2)
	{
		printf("\nThe fact that this condition is true proves that ptr2 points to a completely new block of memory.");
		printf("\nThis proves that realloc(NULL, size) behaves just like malloc(size) as it grabs a random piece of memory.");
	}
	free(ptr);
	ptr = NULL;
	free(ptr2);
	ptr2 = NULL;
	return 0;
}