#include <stdio.h>
#include <stdlib.h>
int* makeEvenArray(int n);

int main(){

	printf("\nEnter number of elements: ");
	int rows;
	scanf("%d", &rows);
	int* array = makeEvenArray(rows);
	for (int i = 0; i < rows; ++i)
	{
		printf("%d ", array[i]);
	}
	free(array);
return 0;
}

int* makeEvenArray(int n)
{
	int* ptr = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		ptr[i]=i*2;
	}

	return ptr;
}