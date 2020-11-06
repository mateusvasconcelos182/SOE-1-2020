#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){

int fp;
char string[15];

fp = open("ola_mundo.txt",O_RDWR | O_CREAT);
if(fp==-1)
{
	printf ("Erro na abertura do arquivo.\n");
	exit (1);
}
strcpy(string,"Olá mundo!\n");
lseek(fp, 0, SEEK_SET); 
write(fp, string, (sizeof(string)));
close(fp);
}