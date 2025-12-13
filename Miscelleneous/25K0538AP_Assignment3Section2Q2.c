#include <stdio.h>

int main()
{
	float C[3]={0}, result=0;
	int choice;
	printf("\n1. Series\n2. Parallel\nEnter your choice: ");
	scanf("%d", &choice);
	if (choice == 1)
	{
		for (int i = 0; i <= 2; ++i)
		{
			printf("\nEnter Capacitance of C%d in Farads: ", i+1);
			scanf("%f", &C[i]);
		}
		result = 1/((1/C[0])+(1/C[1])+(1/C[2]));
		printf("\n\nThe Equivalent Capacitance is %.3f Farads.", result);
	}
	else if (choice == 2)
	{
		for (int i = 0; i <= 2; ++i)
		{
			printf("\nEnter Capacitance of C%d in Farads: ", i+1);
			scanf("%f", &C[i]);
			result+=C[i];
		}
		printf("\n\nThe Equivalent Capacitance is %.3f Farads.", result);
	}
	else
	{
		printf("\nError: Invalid Input.");
	}
	return 0;
}