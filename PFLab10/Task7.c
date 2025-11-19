#include <stdio.h>
#include <string.h>
int main()
{
    char pass1[100];
    char pass2[100];
    printf("Enter your password:");
    fgets(pass1, sizeof(pass1), stdin);
    pass1[strcspn(pass1, "\n")]='\0';
    printf("\n\nConfirm your password:");
    fgets(pass2, sizeof(pass2), stdin);
    pass2[strcspn(pass2, "\n")]='\0';
    if (strcmp(pass1, pass2) == 0)
        printf("\nPassword Successfully created.\n");
    else
        printf("\nPasswords do not match, please try again.\n");
return 0; 
}