#include <stdio.h>
#include <string.h>
struct department
{
	char name[50];
	int blocknumber;
};
struct student
{
	int id;
	char name[50];
	float cgpa;
	struct department dept;
};

int main()
{
	struct student stud;
	printf("Enter Student ID: ");
	scanf("%d", &stud.id);
	printf("\nEnter Student Name: ");
	getchar();
	fgets(stud.name, sizeof(stud.name), stdin);
	printf("\nEnter Student CGPA: ");
	scanf("%f", &stud.cgpa);
	printf("\nEnter Student department: ");
	getchar();
	fgets(stud.dept.name, sizeof(stud.dept.name), stdin);
	printf("\nEnter Department Block Number: ");
	scanf("%d", &stud.dept.blocknumber);

	printf("\n\nStudent Data:");
	printf("\nStudent ID:\t %d", stud.id);
	printf("\nStudent Name:\t %s", stud.name);
	printf("\nStudent CGPA:\t %.3f", stud.cgpa);
	printf("\nDepartment:\t %s", stud.dept.name);
	printf("\nDepartment Block:   %d\n", stud.dept.blocknumber);
	return 0;
}