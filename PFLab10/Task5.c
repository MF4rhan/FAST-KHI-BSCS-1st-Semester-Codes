#include <stdio.h>
#include <string.h>
int main()
{
char original[100];
char backup[100];
printf("Enter original string: ");
fgets(original, 100, stdin);
printf("\n");
original[strcspn(original, "\n")] = 0;
strcpy(backup, original);
printf("The original string is: %s", original);
printf("\nThe backup string is: %s", backup);
return 0;
}