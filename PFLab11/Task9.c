#include <stdio.h>
void check();
int main()
{
	int choice;
	do
	{
		printf("\nPress 1 to call function, any other key to exit.\n");
		scanf("%d", &choice);
		if (choice==1)
		{
			check();
		}
	} while (choice == 1);

	return 0;
}

void check()
{
	static int a=1;
	printf("\nThis Function has been called %d times.\n", a);
	a++;
}