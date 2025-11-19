#include <stdio.h>
#include <string.h>
int main()
{
    char names[3][20];
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter the name of studnet #%d:", i+1);
        fgets(names[i], 20, stdin);
    }
    printf("\nThe input usernames are:\n");
    for (int i = 0; i < 3; i++)
    {
        fputs(names[i], stdout);
    }
return 0;
}