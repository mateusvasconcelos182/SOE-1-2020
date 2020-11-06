#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid, pid_1;	
	int fd[2];	
	char msg[100], rcv[100];
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{
		strcpy(msg,"FILHO1: Quando o vento passa, é a bandeira que se move.");
		pid_1 = getpid();
		
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(2);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na leitura do pipe\n");
			else
			{
				printf("%s\n", rcv);
				pid = fork();

				if(getpid() != pid_1)
				{
					strcpy(msg,"FILHO2: Não, é o vento que se move.");
					if (write(fd[1], msg, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
					{
						sleep(2);
						if (read(fd[0], rcv, sizeof(msg)) < 0)
							printf("Erro na leitura do pipe\n");
						else
							printf("%s\n", rcv);
					}
				}
			}
		}

	}

	else
	{
		sleep(5);
		strcpy(msg,"PAI: Os dois se enganam. É a mente dos senhores que se move.");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na leitura do pipe\n");
			else
				printf("%s\n", rcv);

		}
	}
	return 0;
}