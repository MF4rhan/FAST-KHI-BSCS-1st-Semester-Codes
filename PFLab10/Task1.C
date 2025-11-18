#include <stdio.h>
#include <string.h>
int main()
{
    char messaginger[100];
    printf("Input your sentence:\n");
    fgets(messaginger, sizeof(messaginger), stdin);
    strcat(messaginger, "Falcon");
    printf("The sentence '%s' has %d characters excluding falcon",messaginger, strlen(messaginger)-7);
    //strlen(messaginger)-6 if counting \n as a character, if not, then strlen(messaginger)-7.
return 0;
}
