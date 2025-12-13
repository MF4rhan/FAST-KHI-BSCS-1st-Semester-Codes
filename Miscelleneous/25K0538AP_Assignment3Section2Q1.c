#include <stdio.h>
#include <math.h>

int main()
{
	float EFlux, Area, Angle, rad, Result;
	printf("\nEnter magnitude of Electric Flux: ");
	scanf("%f", &EFlux);
	printf("\nEnter the Area of the rectangular surface: ");
	scanf("%f", &Area);
	printf("\nEnter angle between electric field vector and area vector in Degrees: ");
	scanf("%f", &Angle);
	rad = Angle*(M_PI/180);
	Result = EFlux*Area*cos(rad);
	printf("\n\nThe Electric Flux through the rectangular surface is %.3f", Result);
	printf("\n");
	return 0;
}