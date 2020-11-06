#include <stdio.h>

int main(){

FILE *fp;

fp = fopen("ola_mundo.txt","w" );
fputs("Olá mundo!\n",fp);
fclose(fp);
}