#include <stdio.h>
#include <string.h>
struct bookdata
{
	int id;
	int popularity;
	int lastAccess;
};
void operations(struct bookdata books[], int capacity, int lines, int *currentaccess);
int main()
{
	int capacity, lines, currentaccess=0;
	printf("Enter the capacity of the shelf and number of input commands (separated by a space):\n");
	scanf("%d %d", &capacity, &lines);
	struct bookdata books[capacity];
	printf("\n\n\n");
	operations(books, capacity, lines, &currentaccess);
	printf("\n");
	return 0;
}

void operations(struct bookdata books[], int capacity, int lines, int *currentaccess)
{
	char command[10];
	int tempid, temppop, currentcap=0;
	printf("\nInput\t\tOutput\n");
	for (int i=0; i<lines; ++i)
	{
		//printf("\nEnter Command (ADD ID POPULARITY)(ACCESS ID):\n");
		scanf("%s",command);
		if (strcmp(command, "ADD")==0)
		{
			int found=0;
			scanf("%d %d", &tempid, &temppop);
			for (int j=0; j<currentcap; ++j)
			{
				if (tempid==books[j].id)
				{
					//printf("\nThis book alreadye exists in the database, Updated popularity score.\n");
					books[j].popularity=temppop;
					(*currentaccess)++;
					books[j].lastAccess = (*currentaccess);
					found=1;
					break;
				}	
			}
			if (currentcap == capacity && found==0)
				{
					int smallest, smallestindex;
					//printf("\nShelf capacity is full, the least accessed book has been replaced.\n");
					(*currentaccess)++;
					for (int k=0; k<currentcap; k++)
					{
						if (k==0)
						{
						smallest = books[k].lastAccess;
						smallestindex = k;
						}
						else if (books[k].lastAccess<smallest)
						{
						smallest = books[k].lastAccess;
						smallestindex = k;
						}
					}
					books[smallestindex].lastAccess = (*currentaccess);
					books[smallestindex].id = tempid;
					books[smallestindex].popularity = temppop;
					found=1;
				}
			else if (found==0)
			{
				(*currentaccess)++;
				books[currentcap].id = tempid;
				books[currentcap].popularity = temppop;
				books[currentcap].lastAccess = (*currentaccess);
				currentcap++;
				//printf("\nBook successfully added to the shelf.\n");
			}
		}
		else if (strcmp(command, "ACCESS")==0)
		{
			int found=0;
			scanf("%d", &tempid);
			for (int i=0; i<currentcap; ++i)
			{
				if (books[i].id == tempid)
				{
					printf("\t\t%d\n", books[i].popularity);
					(*currentaccess)++;
					books[i].lastAccess = (*currentaccess);
					found =1;
					break;
				}
			}
			if(found==0)
			{
				printf("\t\t-1\n");
			}
		}
	}
}