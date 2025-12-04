#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int rows;

	printf("\nInput number of rows for the array: ");
	scanf("%d", &rows);
	int** array = (int**)malloc(rows * sizeof(int*));
	int* cols = (int*)malloc(rows * sizeof(int));
	for (int i = 0; i < rows; ++i)
	{
		printf("\nInput number of colums for row %d: ", i+1);
		scanf("%d", &cols[i]);
	}
	for (int i = 0; i < rows; ++i)
	{
		array[i] = (int*)malloc(cols[i] * sizeof(int));
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("\nInput element for %d row %d column: ", i+1, j+1);
			scanf("%d", &array[i][j]);
		}
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%d\t", array[i][j]);
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