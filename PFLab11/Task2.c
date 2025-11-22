#include <stdio.h>
#include <string.h>
struct bookdata
{
    char bookname[30];
    char author[30];
    int pages;
    float price;
};

int main()
{
    struct bookdata books[3];
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter book#%d name:\n", i+1);
        fgets(books[i].bookname, sizeof(books[i].bookname), stdin);
        printf("\nEnter author name:\n");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        printf("\nEnter number of pages:");
        scanf("%d", &books[i].pages);
        printf("\nEnter price:");
        scanf("%f", &books[i].price);
        getchar();
    }
    printf("\n\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Book #%d\nBook Title: %s\nBook Author: %s\nPages: %d\nPrice: %3.f\n\n", i, books[i].bookname, books[i].author, books[i].pages, books[i].price);
    }
    
    return 0;
}