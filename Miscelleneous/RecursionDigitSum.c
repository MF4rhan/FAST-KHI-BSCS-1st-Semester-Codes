#include <stdio.h>
int sum(int num);
int main()
{
	int num, sumo;
	printf("Enter a number:");
	scanf("%d", &num);
	sumo=sum(num);
	printf("The sum of all individual digits is: %d", sumo);
	printf("\n");
	return 0;
}

int sum(int num)
{
	int sumo;
	if (num==0)
	{
		return 0;
	}
	sumo = (num%10) + sum(num/10);
	return sumo;
}