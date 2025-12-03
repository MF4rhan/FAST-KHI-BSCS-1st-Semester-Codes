#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
 string name;
 void virtual showResult()
	{
		cout << "General Student Result" << endl;
	};
};

class ScienceStudent : public Student
{
	 void showResult()
	{
		cout << "Science Student Resutl: Physics-90, Chemistry-85." << endl;
	};
};

class ArtsStudent : public Student
{
	 void showResult()
	{
		cout << "Arts Student Resutl: History-88, Literature-92." << endl;
	};
};

int main()
{
	Student* stud;
	ScienceStudent sstud;
	ArtsStudent astud;
	stud = &sstud;
	stud->showResult();
	stud = &astud;
	stud->showResult();

return 0;
}
