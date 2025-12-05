#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr1 = (int*)malloc(10 *sizeof(int));
	if (arr1==NULL)
	{
		printf("\nMalloc Failed.");
		return 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		arr1[i]=i*10;
	}

	//here we would call free() to free the memory before closing and end the program, but we forgot.
	//now proving that the memory still exists by assinging value.
	arr1[5] = 99;
	printf("\n%d The fact that this got printed proves that the memory still exists", arr1[5]);
	free(arr1);
return 0;
}