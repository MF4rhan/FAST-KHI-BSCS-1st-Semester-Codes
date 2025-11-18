#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int id1, id2, id3;
    FILE *lib;
    lib = fopen("Library.txt","w");
    if(lib == NULL)
    {
        printf("Error");
        exit(1);
    }
    printf("\nEnter the three book IDS.\n");
    scanf("%d %d %d", &id1, &id2, &id3);
    fprintf(lib, "%d %d %d", id1, id2, id3);
    fclose(lib);

    lib = fopen("Library.txt","r");
    if(lib == NULL)
    {
        printf("Error");
        exit(1);
    }
    fscanf(lib, "%d %d %d", &id1, &id2, &id3);
    printf("%d %d %d", id1, id2, id3);
return 0;
}