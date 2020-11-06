#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	int i=0;
	pid_t child_pid[3];
	printf("ID do processo-pai: %d\n", (int) getpid());

	sleep(1);
	child_pid[0] = fork();
	if (child_pid[0] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	sleep(1);
	child_pid[1] = fork();
	if (child_pid[1] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	sleep(1);
	child_pid[2] = fork();
	if (child_pid[2] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	return 0;
}