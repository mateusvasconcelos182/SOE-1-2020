#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, const char * argv[]){

FILE *fp;
char nome[50]="";
char idade[20]="";
char file[55]="";

strcpy(nome, argv[1]);
strcpy(file, argv[1]);
strcpy(idade, argv[2]);
strcat(file, ".txt");
fp = fopen(file,"w+" );
fputs("Nome:",fp);
fputs(nome,fp);
fputs("\nIdade:",fp);
fputs(idade,fp);
fputs(" anos\n",fp);
fclose(fp);
}