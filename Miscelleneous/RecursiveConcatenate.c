#include <stdio.h>
#include <string.h>

char* recursiveConcat(char* dest, char* src)
{
	int len = strlen(dest);
	if (*src == '\0')
	{
		return dest;
	}
	dest[len] = *src;
	dest[len+1]='\0';
	return recursiveConcat(dest,src+1);
}

int main()
{

}

