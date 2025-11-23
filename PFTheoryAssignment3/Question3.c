#include <stdio.h>
#include <string.h>
struct employeeData
{
	int id;
	char name[50];
	char designation[50];
	int salary;
};

void displayEmployees(struct employeeData employees[], int n);
int findHighestSalary(struct employeeData employees[], int n);
void searchEmployee(struct employeeData employees[], int n, int searchid, char searchname[50], int mode);

int main()
{
	int n, choice;
	printf("Enter the number of employees to add: ");
	scanf("%d", &n);
	struct employeeData employees[n];
	for (int i = 0; i < n; ++i)
	{
		printf("\nEnter Employee#%d ID: ", i+1);
		scanf("%d", &employees[i].id);
		printf("\nEnter Employee#%d Name: ",i+1);
		getchar();
		fgets(employees[i].name, sizeof(employees[i].name), stdin);
		employees[i].name[strcspn(employees[i].name, "\n")]='\0';
		printf("\nEnter Employee#%d Designation: ",i+1);
		fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
		employees[i].designation[strcspn(employees[i].designation, "\n")]='\0';
		printf("\nEnter Employee#%d salary: ",i+1);
		scanf("%d", &employees[i].salary);
		getchar();
	}
	do
	{
		printf("\n\n1. Display all employees.\n2. Find highest salary.\n3. Search employee by ID or Name.\n4. Exit program.\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{

		case 1:
			{
				printf("Employee#\tEmployee ID\tName\t\tDesignation\tSalary");
				displayEmployees(employees, n);
				break;
			}

		case 2:
			{
				int sal = findHighestSalary(employees, n)+1;
				printf("\nThe Employee with Highest salary is:");
				printf("\nEmployee#%d ID:\t\t%d", sal, employees[sal].id);
				printf("\nEnter Employee#%d Name:\t\t%s",sal, employees[sal].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", sal, employees[sal].designation);
				printf("\nEnter Employee#%d salary:\t\t%d", sal, employees[sal].salary);
				break;
			}

		case 3:
			{
				int choice2;
				do
				{
					int mode, searchid=0;
					char searchname[50]={0};
					printf("\n1. Search by ID.\n2. Search by Name\n3. Return to main menu.\nEnter your choice: ");
					scanf("%d", &choice2);
					if (choice2==1)
					{
						printf("\nEnter exact Employee ID: ");
						scanf("%d", &searchid);
						mode=1;
						searchEmployee(employees, n, searchid, searchname, mode);
					}
					else if (choice2==2)
					{
						printf("\nEnter exact Employee Name: ");
						getchar();
						fgets(searchname, sizeof(searchname), stdin);
						searchname[strcspn(searchname, "\n")]='\0';
						mode=2;
						searchEmployee(employees, n, searchid, searchname, mode);
					}
					else if (choice!=3)
					{
						printf("\nInvalid choice.\n");
					}
				} while(choice2!=3);
				break;
			}
		case 4:
			break;
		default:
			{
				printf("\nInvalid Input.\n");
				break;
			}
		}

	} while (choice!=4);

	printf("\n");
	return 0;
}

void displayEmployees(struct employeeData employees[], int n)
{
	if (n==0)
		return;
	displayEmployees(employees, n-1);
	printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%d",n,employees[n-1].id,employees[n-1].name,employees[n-1].designation,employees[n-1].salary);
}

int findHighestSalary(struct employeeData employees[], int n)
{
	if (n==1)
	{
		return 0;
	}
	int highestindex = findHighestSalary(employees, n-1);
	if (employees[n-1].salary>employees[highestindex].salary)
	{
		return n-1;
	}
	else
	{
		return highestindex;
	}
}

void searchEmployee(struct employeeData employees[], int n, int searchid, char searchname[50], int mode)
{
	if (mode==1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (employees[i].id==searchid)
			{
				printf("\nEmployee#%d ID:\t\t%d", i+1, employees[i].id);
				printf("\nEnter Employee#%d Name:\t\t%s",i+1, employees[i].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", i+1, employees[i].designation);
				printf("\nEnter Employee#%d salary:\t\t%d", i+1, employees[i].salary);
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (strcmp(employees[i].name, searchname)==0)
			{
				printf("\nEmployee#%d ID:\t\t%d", i, employees[i].id);
				printf("\nEnter Employee#%d Name:\t\t%s",i, employees[i].name);
				printf("\nEnter Employee#%d Designation:\t\t%s", i, employees[i].designation);
				printf("\nEnter Employee#%d salary:\t\t", i, employees[i].salary);
				return;
			}
		}
	}
}