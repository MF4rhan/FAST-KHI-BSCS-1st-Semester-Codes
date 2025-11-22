#include <stdio.h>
#include <string.h>
struct director
{
	char name[50];
	char nationality[50];
};
struct movies
{
	char title[50];
	char genre[50];
	struct director direc;
	int release_year;
	float rating;
};
void addmovie(struct movies moveee[10], int *currentmoveee);
void searchgenre(struct movies moveee[10], int currentmoveee);
void display(struct movies moveee[10], int currentmoveee);
int main()
{
	struct movies moveee[10];
	int currentmoveee=0;
	int choice;
	do
	{
		printf("\n\n1. Add a new movie.\n2. Search a movie by genre.\n3. Display all movies.\n4. Exit program.\nEnter your choice.\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addmovie(moveee, &currentmoveee);
			printf("\nMovie successfully added.\n");
			break;
		case 2:
			searchgenre(moveee, currentmoveee);
			break;
		case 3:
			display(moveee, currentmoveee);
			break;
		case 4:
			break;
		default:
			printf("\nInvalid Choice.\n");
		}
	} while(choice!=4);
	printf("\n");
return 0;
}

void addmovie(struct movies moveee[10], int *currentmoveee)
{
	printf("\nEnter movie name: ");
	getchar();
	fgets(moveee[*currentmoveee].title, sizeof(moveee[*currentmoveee].title), stdin);
	printf("\nEnter the movie genre: ");
	fgets(moveee[*currentmoveee].genre, sizeof(moveee[*currentmoveee].genre), stdin);
	printf("\nEnter the Director's Name: ");
	fgets(moveee[*currentmoveee].direc.name, sizeof(moveee[*currentmoveee].direc.name), stdin);
	printf("\nEnter the Director's nationality: ");
	fgets(moveee[*currentmoveee].direc.nationality, sizeof(moveee[*currentmoveee].direc.nationality), stdin);
	printf("\nEnter release year: ");
	scanf("%d", &moveee[*currentmoveee].release_year);
	printf("\nEnter Movie's rating: ");
	scanf("%f", &moveee[*currentmoveee].rating);
	(*currentmoveee)++;
}

void searchgenre(struct movies moveee[10], int currentmoveee)
{
	char searching[50];
	int flag=0;
	printf("\nEnter the exact genre to search: ");
	getchar();
	fgets(searching, 50, stdin);
	for (int i = 0; i < (currentmoveee); ++i)
	{
		if (strcmp(moveee[i].genre, searching)==0)
		{
			printf("\nMovie Title:\t%s", moveee[i].title);
			printf("Movie Genre:\t%s", moveee[i].genre);
			printf("Movie Director:\t%s", moveee[i].direc.name);
			printf("Movie Director nationality:\t%s", moveee[i].direc.nationality);
			printf("Release Year:\t%d", moveee[i].release_year);
			printf("\nMovie Rating:\t%.1f", moveee[i].rating);
			flag=1;
		}
	}
	if (flag==0)
	{
		printf("\nInvalid Genre or Movie not found.\n");
	}
}

void display(struct movies moveee[10], int currentmoveee)
{
	for (int i = 0; i < currentmoveee; ++i)
	{
		printf("\n\nMovie#%d:", i+1);
		printf("\nMovie Title:\t%s", moveee[i].title);
		printf("Movie Genre:\t%s", moveee[i].genre);
		printf("Movie Director:\t%s", moveee[i].direc.name);
		printf("Movie Director nationality:\t%s", moveee[i].direc.nationality);
		printf("Release Year:\t%d", moveee[i].release_year);
		printf("\nMovie Rating:\t%.1f", moveee[i].rating);
	}
}