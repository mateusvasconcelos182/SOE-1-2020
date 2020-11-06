#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int count; 

void* char_print () 
{
	printf("%d\n", count);
	if(count<10)
		sleep(1);
	return NULL;
}

int main ()
{
	pthread_t thread1_id;
	printf("Pressione CTRL+C para finalizar o programa.\n");
	for(count=1;count<=10;count++)
	{
		pthread_create (&thread1_id, NULL, &char_print, NULL);
		pthread_join (thread1_id, NULL);
	}
	sleep(1);
	return 0;
}