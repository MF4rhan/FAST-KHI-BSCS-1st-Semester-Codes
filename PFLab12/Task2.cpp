#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = (int*)malloc(5*sizeof(int));
	if (ptr == NULL)
	{
		printf("\nMemory Allocaion Failed.");
		return 1;
	}
	for (int i=0; i<5; ++i)
	{
		ptr[i]=i+1;
	}
	for (int i=0; i<6; ++i)
	{
		printf("\n%d", ptr[i]);
	}
	//now trying to double free the pointer.
	free(ptr);
	free(ptr);
	//The result of using free() two times is that (for me atleast):
	//The program still runs for the first time, However, Afterwards the code simply doesn't run and keeps retuning 1 exit status (in my case at least).
	//And the only way to fix it is to Restart DevC++ and then replace your file (in my case at least).
	//Or turning both pointers into comments so it can store the address again (like sir said in the class).
	//using one free() works fine (after I fix the issue above) even after running it multiple times, but using it two times brings the above scenerio.
	return 0;
} 
