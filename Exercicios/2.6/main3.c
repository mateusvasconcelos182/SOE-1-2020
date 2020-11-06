#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i=0;
	char* lista_de_args[] = {NULL, NULL};
	

	for(i=1;i<argc;i++)	
	{
		pid_t child_pid = fork();
		if (child_pid == 0)
		{
			lista_de_args[0] = argv[i];
			execvp(lista_de_args[0], lista_de_args);
			fprintf(stderr, "Erro em %s\n", argv[i]);
			return -1;

		}
		else
			wait(NULL);

	}
	return 0;
}