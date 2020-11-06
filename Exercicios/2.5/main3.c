#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int fp;
	char nome[50]="", idade[20]="", arq[50] = "";

	printf("Digite seu nome:\n");
	scanf("%s",nome);
	printf("Digite sua idade:\n");
	scanf("%s", idade);
	strcpy(arq, nome);
	strcat(arq, ".txt");
	fp = open(arq,O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	lseek(fp, 0, SEEK_SET); 
	write(fp, "Nome: ", (sizeof("Nome: ")));
	write(fp, nome, (sizeof(nome)));
	write(fp, "\nIdade: ", (sizeof("Idade: ")));
	write(fp, idade, (sizeof(idade)));
	write(fp, " anos\n", (sizeof("anos")));
	close(fp);
}