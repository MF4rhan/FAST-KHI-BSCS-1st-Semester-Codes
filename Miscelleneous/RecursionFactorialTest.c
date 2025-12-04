#include <stdio.h>
int fact(int n);
int main()
{
    int num, facto;
    printf("Enter a number:");
    scanf("%d", &num);
    facto = fact(num);
    printf("\nThe Factorial of the number is: %d", facto);
    printf("\n");
return 0;

}

int fact(int n)
{
    int m;
    if (n==1)
    {
        return 1;
    }
    m=n*fact(n-1);
    return m;
}