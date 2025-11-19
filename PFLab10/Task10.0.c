#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char names[5][20];
    char search[20];
    FILE *lib;
    lib = fopen("names.txt", "w");
    if (lib == NULL)
    {
        printf("Error: could not open file.\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter the name of employee #%d:", i+1);
        fgets(names[i], 20, stdin);
        names[i][strcspn(names[i], "\n")]='\0';
        fprintf(lib,"%s\n" ,names[i]);
    }
fclose(lib);
lib = fopen("names.txt", "r");
printf("\nEnter a name to search:");
fgets(search, sizeof(search), stdin);
search[strcspn(search, "\n")] = '\0';
int found=0;
char opensearch[20];
int counta=1;
while (fgets(opensearch, sizeof(opensearch), lib))
{
    if (strstr(opensearch, search) != NULL)
    {
        printf("\nThe employee name found at line #%d on the list.",counta);
        found=1;
    }
    counta++;
}
if (found == 0)
{
    printf("\nEmployee name not found.");
}
fclose(lib);
return 0; 
}
