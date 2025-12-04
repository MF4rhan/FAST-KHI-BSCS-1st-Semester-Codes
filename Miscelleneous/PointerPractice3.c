#include <stdio.h>
#include <stdlib.h>
int** testGrid(int row, int col);
int main()
{
	
	printf("\nEnter number of Patients: ");
	int rows;
	scanf("%d", &rows);
	printf("\nEnter number of tests: ");
	int cols;
	scanf("%d", &cols);
	int **grid = testGrid(rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < rows; ++i)
	{
		free(grid[i]);
	}
	free(grid);
	return 0;
}

int** testGrid(int row, int col)
{
	int** array = (int**)malloc(row*sizeof(int*));
	if (array==NULL)
	{
		printf("\nSpine initialization Failed.");
		exit(1);
	}
	for (int i = 0; i < row; ++i)
	{
		array[i] = (int*)malloc(col*sizeof(int));
		if (array[i]==NULL)
		{
		printf("\nRib initialization Failed.");
		exit(1);
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			array[i][j]=i+j;
		}
	}
	return array;

}