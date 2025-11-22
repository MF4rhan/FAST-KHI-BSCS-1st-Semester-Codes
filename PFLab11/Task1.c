#include <stdio.h>
int sum(int n);
int main()
{
    int num, sumo;
    printf("Enter a number:");
    scanf("%d", &num);
    sumo=sum(num);
    printf("\nThe sum of individual digts of %d is %d.", num, sumo);
    return 0;
}

int sum(int n)
{
    if(n<=0)
        return 0;
    return n%10 +sum(n/10);
}
