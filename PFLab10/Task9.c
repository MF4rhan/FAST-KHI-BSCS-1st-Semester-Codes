#include <stdio.h>
#include <string.h>
int main()
{
    char names[3][20];
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter the name of studnet #%d:", i+1);
        fgets(names[i], 20, stdin);
        names[i][strcspn(names[i], "\n")]='\0';
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Characters in name %d:\n", i+1);
        for (int j = 0; names[i][j] != '\0'; j++)
            printf(" %c ", names[i][j]);
        printf("\n\n");
    }
return 0;
}