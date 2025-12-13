#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int m, int n);
void destroy_matrix(int** p);

int main()
{
	int rows, cols;
	int** array = NULL;
printf("\nEnter number of Rows for array: ");
scanf("%d", &rows);
printf("\nEnter number of Columns for array: ");
scanf("%d", &cols);
array = create_matrix(rows, cols);

destroy_matrix(array);
return 0;
}

int** create_matrix(int m, int n)
{
	int **p = (int**)malloc(m*sizeof(int*));
	if (p == NULL)
	{
		printf("\nMalloc Failed.");
		exit(1);
	}
	int* ptr = (int*)malloc(m*n*sizeof(int));
	if (ptr == NULL)
	{
		printf("\nMalloc Failed.");
		free(p);
		exit(1);
	}
	for (int i = 0; i < m; ++i)
	{
		p[i] = &ptr[i*n];
	}
	return p;
}

void destroy_matrix(int** p)
{
	free(p[0]);
	free(p);
}