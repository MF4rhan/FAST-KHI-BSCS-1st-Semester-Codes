#include <iostream>
using namespace std;

class Employees
{
public:
	string name;
	int salary;
	void virtual calculateBonus()
	{
		cout << "\nBase Employee bonus is 1000." << endl;
	}
};

class Manager : public Employees
{
public:
	void calculateBonus()
	{
		cout << "\nManager bonus is 5000." << endl;
	}
};

class Developer : public Employees
{
public:
	void calculateBonus()
	{
		cout << "\nDeveloper bonus is 3000." << endl;
	}
};

int main()
{
	Employees* emps[2];
	Developer dev;
	Manager manag;
	emps[0] = &manag;
	emps[1] = &dev;

	for (int i = 0; i < 2; ++i)
	{
		cout << "\nEnter Employee#" << i+1 << " Name: " << endl;
		cin >> emps[i]->name;
		cout << "\nEnter Employee#" << i+1 << " salary: " << endl;
		cin >> emps[i]->salary;
	}

	for (int i = 0; i < 2; ++i)
	{
		cout << "\nEnter Employee#" << i+1 << " Name: " << emps[i]->name << endl;
		cout << "\nEnter Employee#" << i+1 << " Salary: " << emps[i]->salary << endl;
		emps[i] -> calculateBonus();
	}
return 0;
}