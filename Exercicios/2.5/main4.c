#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{

	int fp, i=0;
	char nome[50]="";
	char idade[20]="";
	char file[55]="";


	for(i=1; i<=(argc-2); i++)
	{
		if(i==1)
			strcpy(nome, argv[i]);
		else
		{	
			strcat(nome, " ");
			strcat(nome, argv[i]);
		}
	}
	strcpy(file, nome);
	strcpy(idade, argv[argc-1]);
	strcat(file, ".txt");
	fp = open(file, O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		printf("file: %s\nnome: %s\n", file, nome);
		exit (-1);
	}
	lseek(fp, 0, SEEK_SET); 
	write(fp, "Nome: ", (sizeof("Nome: ")));
	write(fp, nome, (sizeof(nome)));
	write(fp, "\nIdade: ", (sizeof("Idade: \n")));
	write(fp, idade, (sizeof(idade)));
	write(fp, "\nanos", (sizeof("anos\n")));
	close(fp);
}