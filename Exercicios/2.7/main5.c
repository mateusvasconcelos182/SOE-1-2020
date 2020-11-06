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
	char msg[100], rcv[100];
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{
		strcpy(msg,"FILHO: Pai, qual é a verdadeira essência da sabedoria?");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(5);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na escrita do pipe\n");
			else
			{
				printf("%s\n", rcv);
				strcpy(msg,"FILHO: Mas até uma criança de três anos sabe disso!");
				if (write(fd[1], msg, sizeof(msg)) < 0)
					printf("Erro na escrita do pipe\n");
				else
				{
					sleep(1);
					if (read(fd[0], rcv, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
						printf("%s\n", rcv);
				}
			}
		}

	}

	else
	{
		sleep(5);
		strcpy(msg,"PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(5);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na escrita do pipe\n");
			else
			{
				printf("%s\n", rcv);
				strcpy(msg,"PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
				if (write(fd[1], msg, sizeof(msg)) < 0)
					printf("Erro na escrita do pipe\n");
				else
				{
					sleep(1);
					if (read(fd[0], rcv, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
						printf("%s\n", rcv);
				}
			}
		}
	}
	return 0;
}