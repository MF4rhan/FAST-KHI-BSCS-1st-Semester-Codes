#include <stdio.h>
#include <stdlib.h>
void increaseSize(int **list,int i);
int main()
{
	printf("\nEnter initial size of list: ");
	int size;
	scanf("%d", &size);
	int* list = (int*)malloc(size*sizeof(int));
	if (list == NULL)
	{
		printf("\nMalloc Failed.");
		return 1;
	}
	for(int i = 0;; ++i)
	{
		if (i<size)
		{
		printf("\nEnter Reading#%d: ", i);
		scanf("%d", &list[i]);
		}
		else
		{
		increaseSize(&list, i);
		printf("\nEnter Reading#%d: ", i);
		scanf("%d", &list[i]);
		}
	}
	free(list);
}

void increaseSize(int **list, int i)
{
	int* tempo = (int*)realloc((*list), (i+1)*sizeof(int));
	if (tempo==NULL)
	{
		printf("\nReallock Failed");
		exit(1);
	}
	else
	{
		(*list)=tempo;

	}
}