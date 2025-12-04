#include <stdio.h>
void series(int num);
int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d", &num);
	series(num);
	printf("\n");
return 0;
}

void series(int num)
{
	if (num==0)
	{
		return;
	}
	printf("%d ",num);
	series(num-1);
}
