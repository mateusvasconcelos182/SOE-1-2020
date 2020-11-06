#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual);

int main()
{
	int i=0;
	pid_t child_pid;
	for(i=0;i<3;i++)
	{
		child_pid = fork();
		if(child_pid == 0 && v_global== 0)
			Incrementa_Variavel_Global((int)getpid());
		else
			wait(NULL);
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}