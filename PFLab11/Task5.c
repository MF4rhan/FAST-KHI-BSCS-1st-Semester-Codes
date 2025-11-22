#include <stdio.h>
#include <string.h>
void reverse(char message[100], int len);
int main()
{
	char message[100];
	int len;
	printf("Enter your secret message:\n");
	fgets(message, sizeof(message), stdin);
	len = strlen(message);
	reverse(message, len);
	printf("\n");
	return 0;
}

void reverse(char message[100], int len)
{
	if (len<0)
	{
		return;
	}
	printf("%c", message[len]);
	reverse(message, len-1);
}