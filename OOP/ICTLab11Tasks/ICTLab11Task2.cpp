#include <iostream>
using namespace std;
class Employee
{
public:
	void work()
	{
	cout << "\nEmployee is working"<< endl;
	}
};

class Manager : public Employee
{
public:
	void work()
	{
	cout << "\nManager is managing work"<< endl;
	}
};

int main()
{
	Employee Emp;
	Manager Manag;
	
	Emp.work();
	Manag.work();
return 0;
}