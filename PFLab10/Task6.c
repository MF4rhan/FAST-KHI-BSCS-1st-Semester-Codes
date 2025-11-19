#include <stdio.h>
#include <string.h>
int main()
{
    char name1[100];
    char name2[50];
    printf("Enter name of first person:");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1 ,"\n")]='\0';
    printf("\nEnter name of second person:");
    fgets(name2, sizeof(name1), stdin);
    name2[strcspn(name2 ,"\n")]='\0';
    strcat(name1, name2);
    printf("\n\nThe combined name is %s", name1);
return 0;
}