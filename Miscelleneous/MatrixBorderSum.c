#include <stdio.h>

int main()
{
	int n=3;
	int sum=0;
	int matrix[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i==0)
			{
				sum+=matrix[i][j];
			}
			else if (i==n-1)
			{
				sum+=matrix[i][j];
			}
			else
			{
				if (j==0)
				{
					sum+=matrix[i][j];
				}
				else if (j==n-1)
				{
					sum+=matrix[i][j];
				}
			}	
		}	
	}
	printf("\nThe sum of border is %d", sum);

	return 0;
}