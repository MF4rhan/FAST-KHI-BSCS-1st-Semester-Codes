#include <iostream>
#include <string>
using namespace std;


class Vehicle
{
public:
	string brand = "Honda";
	int speed = 100;
	void showInfo()
	{
		cout << "Brand: "<< brand <<endl;
		cout << "Speed: "<< speed <<endl;
	};
};

class Car : public Vehicle
{
public:
	string fueltype;
	void showCarInfo()
	{
		cout << "Brand: "<< brand <<endl;
		cout << "Speed: "<< speed <<endl;
		cout << "Fuel Type: "<< fueltype <<endl;
	};
};

int main()
{
	Car weee;
	weee.brand = "Lexus";
	weee.speed = 120;
	weee.fueltype = "diesel";
	weee.showInfo();
	weee.showCarInfo();
return 0;
}