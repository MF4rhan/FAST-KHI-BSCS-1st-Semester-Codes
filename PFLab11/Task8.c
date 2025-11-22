#include <stdio.h>
#include <string.h>

struct employee
{
	int id;
	char name[50];
	int salary;
	char position[50];
};

int main()
{
	struct employee emps[5];
	int i, highest=0, num=0;
	for (i = 0; i < 5; ++i)
	{
	printf("Enter employee#%d ID: ", i+1);
	scanf("%d", &emps[i].id);
	printf("\nEnter employee#%d name: ", i+1);
	getchar();
	fgets(emps[i].name, sizeof(emps[i].name), stdin);
	printf("\nEnter employee#%d salary: ", i+1);
	scanf("%d", &emps[i].salary);
	if (emps[i].salary > highest)
	{
		highest=emps[i].salary;
		num=i;
	}
	printf("\nEnter employee#%d position: ", i+1);
	getchar();
	fgets(emps[i].position, sizeof(emps[i].position), stdin);
	}
	printf("\n\nThe highest salary belongs to:");
	printf("employee ID:\t%d\nEmployee Name:\t%sSalary:\t%d\nPosition:\t%s\n", emps[num].id,emps[num].name,emps[num].salary,emps[num].position);
	return 0;
}