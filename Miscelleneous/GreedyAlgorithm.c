#include <stdio.h>

int maxprof(int difficulty[], int profit[], int worker[], int m, int n);

int main()
{
int difficulty[] = {5, 5, 5, 20};
int profit[] = {10, 20, 30, 100};
int worker[] = {6, 6, 6, 5};
// Expected Output: 60

	int m = sizeof(worker)/4;
	int n = sizeof(difficulty)/4;

	int result = maxprof(difficulty,profit, worker, m, n );

	printf("\nThe maximum profit is %d", result);
	return 0;

}


int maxprof(int difficulty[], int profit[], int worker[], int m, int n)
{
	int total=0;
	for (int i = 0; i < m; ++i)
	{
		int highest=0;
		for (int j = 0; j < n; ++j)
		{
			if (worker[i]>=difficulty[j])
			{
				if (profit[j]>highest)
				{
					highest = profit[j];
				}
			}
		}
		total+=highest;
	}

	return total;
}