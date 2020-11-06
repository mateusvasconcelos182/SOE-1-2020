#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

FILE *fp;
char nome[50]="", idade[20]="";

fp = fopen("nome_idade.txt","w+" );
printf("Digite seu nome:\n");
scanf("%s",nome);
printf("Digite sua idade:\n");
scanf("%s", idade);
fputs("Nome:",fp);
fputs(nome,fp);
fputs("\nIdade:",fp);
fputs(idade,fp);
fputs(" anos\n",fp);
fclose(fp);
}