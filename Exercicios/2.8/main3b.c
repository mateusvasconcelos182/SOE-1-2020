#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int max;
	};

struct max_parms
	{	
	long int max[4];
	long int ultimate_max;
	};
	
	int count=0;

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	count++;
	printf("\n\n\n\n--------------------------Vetor V (parte %d)--------------------------\n\n\n\n", count);
	for(i=0; i<=(MAX-1); i++)
	{
		p->v[i] = random();
		printf("  %ld  ", p->v[i]);
	}
	p->max = p->v[0];
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->max)
			p->max = p->v[i];
	}
	printf("Valor máximo (parte %d):%ld\n", count, p->max);
	return NULL;
}

int main ()
{
	int i=0;
	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	struct char_print_parms thread3_args;
	struct char_print_parms thread4_args;
	struct max_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.max[0] = thread1_args.max;
	thread5_args.max[1] = thread2_args.max;
	thread5_args.max[2] = thread3_args.max;
	thread5_args.max[3] = thread4_args.max;

	thread5_args.ultimate_max = thread5_args.max[0];

	for (i = 0; i < 4; i++)
	{
		if(thread5_args.max[i]>thread5_args.ultimate_max)
			thread5_args.ultimate_max = thread5_args.max[i];
	}
	printf("\n\n\n-------------------------- Valor máximo final: %ld--------------------------", thread5_args.ultimate_max);
	
	
	return 0;

}