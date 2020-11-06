#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, const char *argv[])
{
	int i=1;
	while(i<argc)
	{
		system(argv[i]);
		i++;
	}
	return 0;
}