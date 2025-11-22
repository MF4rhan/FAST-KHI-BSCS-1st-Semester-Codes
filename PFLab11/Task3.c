#include <stdio.h>
#include <string.h>
struct Flight
{
	int flight_number;
	char departure_city[30];
	char destination_city[30];
	char date[12];
	int avaliable_seats;
};
void bookseat(struct Flight tickets[5], int *current);
void addflight(struct Flight tickets[5], int *current);
void allflights(struct Flight tickets[5], int *current);
int main()
{
	struct Flight tickets[5];
	int choice, current=0;
	do
	{
		printf("\n\nWelcome to Fight System.");
		printf("\n 1. Add a flight.");
		printf("\n 2. Book a seat.");
		printf("\n 3. Show all flights.");
		printf("\n 4. Exit the system.");
		printf("\nEnter your choice.\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addflight(tickets, &current);
			break;
		case 2:
			bookseat(tickets, &current);
			break;
		case 3:
			allflights(tickets, &current);
			break;
		case 4:
			break;
		default:
			printf("\nInvalid Choice.\n");
			break;
		}
	} while (choice!=4);
	printf("\n");
return 0;
}

void addflight(struct Flight tickets[5], int *current)
{
	printf("\nEnter your flight number: ");
	scanf("%d", &tickets[*current].flight_number);

	printf("\nEnter your departure city: ");
	getchar();
	fgets(tickets[*current].departure_city, sizeof(tickets[*current].departure_city), stdin);
	tickets[*current].departure_city[strcspn(tickets[*current].departure_city, "\n")]='\0';

	printf("\nEnter your destination city: ");
	fgets(tickets[*current].destination_city, sizeof(tickets[*current].destination_city), stdin);
	tickets[*current].destination_city[strcspn(tickets[*current].destination_city, "\n")]='\0';

	printf("\nEnter your flight date: ");
	fgets(tickets[*current].date, sizeof(tickets[*current].date), stdin);
	tickets[*current].date[strcspn(tickets[*current].date, "\n")]='\0';

	printf("\nEnter the number of avaliable seats: ");
	scanf("%d", &tickets[*current].avaliable_seats);

	(*current)++;
}

void bookseat(struct Flight tickets[5], int *current)
{
	int tempflight, seats;
	printf("\nEnter the flight number of the flight: ");
	scanf("%d", &tempflight);
	for (int i = 0; i < (*current); i++)
	{
		if (tickets[i].flight_number == tempflight)
		{
			printf("\nThere are %d seats avaliable, Enter the number of seats to book: ", tickets[i].avaliable_seats);
			scanf("%d", &seats);
			if (seats <= tickets[i].avaliable_seats)
			{
				tickets[i].avaliable_seats-=seats;
				printf("\nSeats have been booked.\n");
				return;
			}
			else
			{
				printf("\nNot enough seats avaliable.\n");
				return;
			}
		}
	}
	printf("\nInvalid flight number.\n");
	return;
}

void allflights(struct Flight tickets[5], int *current)
{
	printf("\nAll Current Flights\n");
	for (int i = 0; i < (*current); ++i)
	{
		printf("\nFlight Number: %d", tickets[i].flight_number);
		printf("\nDeparture City: %s", tickets[i].departure_city);
		printf("\nDestination City: %s", tickets[i].destination_city);
		printf("\nDate of Flight: %s", tickets[i].date);
		printf("\nAvaliable Seats: %d", tickets[i].avaliable_seats);
		printf("\n");
	}
}
