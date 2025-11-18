#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char product1[20];
    char product2[20];
    int compare;
    printf("\nEnter your Product Code:");
    fgets(product1, sizeof(product1), stdin);
    product1[strcspn(product1, "\n")] = 0;
    printf("\nEnter the product code to compare:");
    fgets(product2, sizeof(product2), stdin);
    product1[strcspn(product2, "\n")] = 0;
    printf("\nNumber of first letters to comapare:");
    scanf("%d", &compare);
    if (compare <= 0)
    {
        printf("\nInvalid Length.");
        exit(1);
    }
    else if (compare > strlen(product1) || compare > strlen(product2))
    {
        printf("\nYou are comparing more characters than the code contains, exiting program.");
        exit(1);
    }
    
    if (strncmp(product1, product2, compare))
    {
        printf("\nThe products are not from the same category.");
    }
    else
    {
        printf("\nThe products are from the same category.");
    }
    
return 0;
}