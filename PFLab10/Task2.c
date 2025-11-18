#include <stdio.h>
#include <string.h>
int main()
{
    char *pointingthing;
    char gamer[10], finder;
    printf("Enter your word:\n");
    scanf("%s", gamer);
    printf("\nEnter the letter you want to find;\n");
    scanf(" %c", &finder);
    pointingthing = strchr(gamer, finder);
    if (strchr(gamer, finder) != NULL)
        printf("\nCharacter %c found at position %d (index of array)", finder, pointingthing-gamer);
        //the position is technically the index of the array.
    else
        printf("\nCharacter not Found.");
return 0;
}