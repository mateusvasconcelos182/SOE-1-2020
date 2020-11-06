//(A)Valor Médio

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int avg;
	};

struct avg_parms
	{	
	long int avg[4];
	long int ultimate_avg;
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
	p->avg = 0;
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->avg)
			p->avg = p->avg + p->v[i];
	}
	p->avg = p->avg/MAX;
	printf("Valor médio (parte %d):%ld\n", count, p->avg);
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
	struct avg_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.avg[0] = thread1_args.avg;
	thread5_args.avg[1] = thread2_args.avg;
	thread5_args.avg[2] = thread3_args.avg;
	thread5_args.avg[3] = thread4_args.avg;

	thread5_args.ultimate_avg = 0;

	for (i = 0; i < 4; i++)
	{
		thread5_args.ultimate_avg = thread5_args.ultimate_avg + thread5_args.avg[i];
	}
	thread5_args.ultimate_avg = thread5_args.ultimate_avg/4;
	printf("\n\n\n-------------------------- Valor médio final: %ld--------------------------", thread5_args.ultimate_avg);
	
	
	return 0;

}


//////////////////////////////////////////////////////////////////////////////////////

//(B)


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int avg;
	long int var;
	};

struct var_parms
	{	
	long int avg[4];
	long int ultimate_avg;
	long int ultimate_var;
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
//		printf("  %ld  ", p->v[i]);
	}
	p->avg = 0;
	p->var = 0;
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->avg)
			p->avg = p->avg + p->v[i];
			p->var = p->var + (p->v[i])^2;
	}
	p->avg = p->avg/MAX;
	p->var = (p->var - MAX*(p->avg)^2)/(MAX-1);
	printf("Variância (parte %d):%ld\n", count, p->avg);
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
	struct var_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.avg[0] = thread1_args.avg;
	thread5_args.avg[1] = thread2_args.avg;
	thread5_args.avg[2] = thread3_args.avg;
	thread5_args.avg[3] = thread4_args.avg;

	thread5_args.ultimate_avg = 0;
	thread5_args.ultimate_var = 0;
	for (i = 0; i < 4; i++)
	{
		thread5_args.ultimate_avg = thread5_args.ultimate_avg + thread5_args.avg[i];
		thread5_args.ultimate_var = thread5_args.ultimate_var + (thread5_args.avg[i])^2;
	}
	thread5_args.ultimate_avg = thread5_args.ultimate_avg/4;
	
	thread5_args.ultimate_var = thread5_args.ultimate_var - (4*thread5_args.ultimate_avg)^2/3;

	printf("\n\n\n-------------------------- Variância final: %ld--------------------------", thread5_args.ultimate_var);
	
	
	return 0;

}