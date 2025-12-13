#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int capacity = 2;
	int count = 0;
	char** storage = (char**)calloc(capacity, sizeof(char*));
	if (storage == NULL)
	{
		printf("\nStorage memory allocation failed.");
		exit(1);
	}
	char* concat = NULL;
	char* tempo = NULL;
	char** tempoo = NULL;
	char temp[20];
	int size;
	printf("\nEnter your first string: ");
	scanf("%s", temp);
	size = strlen(temp)+1;
	concat = (char*)malloc(size*sizeof(char));
	if (concat == NULL)
	{
		printf("\nConcate memory allocation failed.");
		free(storage);
		exit(1);
	}
	tempo = (char*)malloc(size*sizeof(char));
	if (tempo == NULL)
	{
		printf("\nStorage First string Malloc failed.");
		exit(1);
	}
	storage[count] = tempo;
	tempo = NULL;
	strcpy(storage[count], temp);
	strcpy(concat, temp);
	count++;
	while(1)
	{
		printf("\nEnter new String or press Q to exit: ");
		scanf("%s", temp);

		if (strcmp(temp, "Q")== 0)
		{
			break;
		}

		size = strlen(temp);

		tempo = (char *)realloc(concat, strlen(concat)+size+1);
		if (tempo == NULL)
		{
			printf("\nConcate Realloc Failed");
			break;
		}
		concat = tempo;
		tempo = NULL;
		if (count >= capacity)
		{
			tempoo = (char**)realloc(storage, sizeof(char*)*(capacity+1));
			if (tempoo == NULL)
			{
				printf("\nStorage Realloc Failed.");
				break;
			}	
			storage = tempoo;
			
			tempoo = NULL;
			capacity++;
		}
		tempo = (char*)malloc((size+1)*sizeof(char));
		if (tempo == NULL)
		{
			printf("\nNew Storage string Malloc failed.");
			break;
		}
		storage[count] = tempo;
		tempo = NULL;
		strcat(concat, temp);
		strcpy(storage[count], temp);
		count++;
	}
	printf("\n\nOriginal String inputs:\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%s\n", storage[i]);
	}

	printf("\nFinal Concatenated String:\n");
	printf("\n%s", concat);

	for (int i = 0; i < count; ++i)
		{
			free(storage[i]);
		}
	free(storage);
	free(concat);
	return 0;
}