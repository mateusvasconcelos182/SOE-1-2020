#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, i=0, found=0;
	char c, word[strlen(argv[1])], wf[strlen(argv[1])];

	
	strcpy(word, argv[1]);
	fp = open (argv[2], O_RDONLY);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	printf("Palavra: %s\n", word);
	while(read(fp, &c, 1) != 0)
	{
		if((c==' ' || c=='\n') && (i==strlen(word)))
			found++;
		if(c==' ' || c=='\n')
			i=0;		
		if(word[i]==c)
			i++;

	}
	printf("\nNúmero de ocorrências da palavra %s: %d.\n", word, found);
	close(fp);
	
	return 0;
}