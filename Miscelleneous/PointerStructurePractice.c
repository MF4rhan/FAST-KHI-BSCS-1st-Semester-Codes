#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void update(struct book** books, int num, char temp[], float tempo);

struct book
{
char name[50];
float rating;
};

int main()
{
	int num;
	printf("\nEnter number of books: ");
	scanf("%d", &num);
	getchar();
struct book* books = (struct book*)malloc(num*sizeof(struct book));
if (books == NULL)
{
	printf("\nMalloc Failed.");
	return 1;
}

for (int i = 0; i < num; ++i)
{
	printf("\nEnter Book#%d Name: ", i+1);
	fgets(books[i].name,50, stdin);
	books[i].name[strcspn(books[i].name, "\n")] = '\0';
	printf("\nEnter Book#%d Rating: ", i+1);
	scanf("%f", &books[i].rating);
	getchar();
}
printf("\nEnter new book's name: ");
char temp[50];
fgets(temp, 50, stdin);
temp[strcspn(temp, "\n")]= '\0';
printf("\nEnter new book's rating: ");
float tempo;
scanf("%f", &tempo);
update(&books, num, temp, tempo);
num++;

for (int i = 0; i < num; ++i)
{
	printf("\nBook#%d Name: %s", i+1, books[i].name);
	printf("\nBook#%d Rating: %.1f", i+1, books[i].rating);
}
free(books);
return 0;

}

void update(struct book** books, int num, char temp[], float tempo)
{
	struct book* tempi = (struct book*)realloc((*books),(num+1)*sizeof(struct book));
	if (tempi==NULL)
	{
		printf("\nReallock Failed");
		exit(1);
	}
	else
	{
		strcpy(tempi[num].name, temp);
		tempi[num].rating = tempo;
		(*books)=tempi;
	}
}