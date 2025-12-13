#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int rows=10;
	int** array = (int**)malloc(rows * sizeof(int*));
	int* cols = (int*)malloc(rows * sizeof(int));

	for (int i = 0; i < rows; ++i)
	{
		printf("\nInput number of colums for row %d: ", i+1);
		scanf("%d", &cols[i]);
		array[i] = (int*)malloc(cols[i] * sizeof(int));
	}


	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
		array[i][j] = i+1;
		}
	}
	printf("\n\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < rows; ++i)
	{
		free(array[i]);
	}
	free(array);
	free(cols);
	array = NULL;
	cols = NULL;
	return 0;
	
}