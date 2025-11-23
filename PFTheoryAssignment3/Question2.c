#include <stdio.h>
void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets);
int main()
{
	int fuel=100, consumption=10, recharge=5, solarBonus=15, planet=1, totalPlanets;
	printf("The journey will start with 100 fuel, with 10 fuel consumption per planet.\nEnter Total number of planets to travel: ");
	scanf("%d", &totalPlanets);
	calculateFuel(fuel, consumption, recharge, solarBonus, planet, totalPlanets);
	printf("\n");
	return 0;
}

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets)
{

	if(planet>totalPlanets)
	{
		printf("\nThe journey has been successfully completed.");
		return;
	}
	else if (fuel==0)
	{
		printf("\nThe fuel has been exchausted, journey incomplete.");
		return;
	}
	if (planet%3==0) //No pattern was given in the question, therefore I have assumed the gravitational zones occur ever 3 planets.
	{
		printf("\nExtra 5 fuel renegerated due to gravitational assists.");
		fuel+=recharge;
	}
	else if (planet%4==0)
	{
		printf("\nExtra 15 fuel renegerated due to Solar.");
		fuel+=solarBonus;
	}
	fuel-=consumption;
	printf("\nPlanet %d: Fuel remaining = %d", planet, fuel);
	calculateFuel(fuel, consumption, recharge, solarBonus, planet+1, totalPlanets);
}