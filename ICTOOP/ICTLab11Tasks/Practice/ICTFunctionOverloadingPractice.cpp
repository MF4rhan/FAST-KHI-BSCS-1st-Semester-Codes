#include <iostream>
#include <string>
using namespace std;

class Discount
{
public:
	float applyDiscount(int a , int b)
	{
		return (a+b)*0.90;
	};
	float applyDiscount(int a , int b, int c)
	{
		return (a+b+c)*0.85;
	};
};

int main()
{
	int choice;
	int item1=0, item2=0, item3=0;
	float result=0;
	Discount something;
	cout << "2 items or 3 items?" <<endl;
	cin >> choice;
	if (choice ==2)
	{
		cout << "Enter 2 items prices:" << endl;
		cin >> item1;
		cin >> item2;
		result = something.applyDiscount(item1, item2);
		cout << "\nThe final price is" <<result<< endl;
	}
	else if (choice == 3)
	{
		cout << "Enter 3 items prices:" << endl;
		cin >> item1;
		cin >> item2;
		cin >> item3;
		result = something.applyDiscount(item1, item2, item3);
		cout << "\nThe final price is " <<result<< endl;
	}
	return 0;
}
