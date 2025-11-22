#include <stdio.h>
int expo(int num, int power);
int main()
{
	int num, power, final;
	printf("Enter the Number: ");
	scanf("%d", &num);
	printf("\nEnter the exponent: ");
	scanf("%d", &power);
	final = expo(num, power);
	printf("\nThe number is %d", final);
	printf("\n");
	return 0;
}

int expo(int num, int power)
{
	if (power==0)~~
	{
		return 1;
	}
	power--;
	return num * expo(num,power);
}