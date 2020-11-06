#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i=1, nro;
	int pid;	
	int fd[2];	
	
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{	
		for(i=1;i<=10;i++)
		{
			if(read(fd[0], &nro, sizeof(int)) < 0)
				printf("Erro na leitura do pipe\n");
			else	
				printf("%d\n", nro);
		}	
	}

	else
	{
		for(i=1;i<=10;i++)
		{
			if (write(fd[1], &i, sizeof(int)) < 0)
				printf("Erro na escrita do pipe\n");
			sleep(1);
		}
	}
	return 0;
}