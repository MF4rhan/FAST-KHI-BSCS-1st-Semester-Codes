#include <stdio.h>
void cal(int n);
int main()
{
    float rad;
    printf("Enter the radius of the circle:");
    scanf("%f", &rad);
    cal(rad);
    return 0;
}

void cal(int n){
    const float pi = 3.14;
    float circum = 2*pi*n;
    printf("The Circumference is: %.3f", circum);
    printf("\n");
    float area = pi*n*n;
     printf("The Area is: %.3f", area);
}