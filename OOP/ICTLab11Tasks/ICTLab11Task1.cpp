#include <iostream>
using namespace std;

class Person
{
public:
	string name;
	int age;
	void display()
	{
	cout << "\n\nName: " << name << "\nAge: "<< age << endl;
	}
};

class student : public Person
{
public:
	int RollNumber;
	void showRoll()
	{
	cout << "Roll Number: " << RollNumber << endl;
	}
};

int main()
{
	student Stud;
	cout << "\nEnter Student Name: " << "\n";
	cin >> Stud.name;
	cout << "\nEnter Student Age: " << "\n";
	cin >> Stud.age;
	cout << "\nEnter Student Roll Number: " << "\n";
	cin >> Stud.RollNumber;
	Stud.display();
	Stud.showRoll();
return 0;
}