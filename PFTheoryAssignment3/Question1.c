#include <stdio.h>
#include <math.h>
void calculateRepayment(float loan,float interestRate,int years);
int main()
{
	int years;
	float loan,interestRate;
	
	printf("Enter Loan: ");
	scanf("%f", &loan);
	printf("\nEnter Years: ");
	scanf("%d", &years);
	printf("\nEnter Interest Rate percentage: ");
	scanf("%f", &interestRate);
	interestRate/=100;
	calculateRepayment(loan, interestRate, years);
	printf("\n");
	return 0;
}

void calculateRepayment(float loan,float interestRate,int years)
{
	float installment;
	static float totalrepay=0;
	static int i=1;
	if (years==0 || loan<1)
	{
		printf("\n\nThe total repayment will be %.3f", totalrepay);
		return;
	}
	installment = (loan * interestRate*pow(1+interestRate, years))/(pow(1+interestRate, years)-1);
	totalrepay+=installment;
	loan = (loan + loan*interestRate)-installment;
	printf("\nYear %d: Remaining Loan = %.1f", i, loan);
	++i;
	--years;
	calculateRepayment(loan, interestRate, years);
}

