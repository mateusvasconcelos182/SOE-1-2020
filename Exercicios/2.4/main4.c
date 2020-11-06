#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	  FILE *arq;
	  char word[20];
	  int i=0, found=0, l=0;


	  arq = fopen(argv[2], "rt");
	  if (arq == NULL)  
	  {
	     printf("Problemas na abertura do arquivo\n");
	     return 0;
	  }
	  fseek(arq, 0, SEEK_SET);
	strcpy(word, "");
	while(!feof(arq))
	{
		  if(fgetc(arq)!=32 && (!feof(arq)))
		  {	
			fseek(arq, i, SEEK_SET);
			while(fgetc(arq) != ' ' && (!feof(arq)))
			{
				word[l]=fgetc(arq);
				l++;
			}
			i+= l;
			l=0;
			if(word==argv[1])
			{
				found++;
			}		
			strcpy(word, "");	
			
		  }
 	}
	  fclose(arq);
	  printf("Número de ocorrências da palavra '%s': %d\n", argv[1], found);
	  return 0;
}