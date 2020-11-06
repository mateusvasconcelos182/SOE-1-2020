//Cliente:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char* const argv[])
{
	int socket_id;
	struct sockaddr socket_struct;
	int numbers;


	socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
	socket_struct.sa_family = AF_LOCAL;
	strcpy(socket_struct.sa_data,"/tmp/socket1");
	
	connect(socket_id,&socket_struct,sizeof(socket_struct));

	for(numbers=1;numbers<=10;numbers++){
		write(socket_id,&numbers,sizeof(int));
		printf("O cliente está enviando = %d\n",numbers);
		sleep(1);
	}
	
	close(socket_id);

	sleep(1);

	return 0;
}

//Servidor:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>

int socket_id;
void sigint_handler(int signum);
void print_numbers(int socket_id_client);
void end_server(void);

int main (int argc, char* const argv[])
{

	struct sockaddr socket_struct;
	
	signal(SIGINT, sigint_handler);
	socket_id = socket(PF_LOCAL,SOCK_STREAM,0);

	socket_struct.sa_family = AF_LOCAL;
	strcpy(socket_struct.sa_data,"/tmp/socket1");
	bind(socket_id,&socket_struct,sizeof(socket_struct));
	listen(socket_id,2);

	while(1){

		struct sockaddr client;
		int socket_id_client;
		socklen_t cliente_len;

		socket_id_client = accept(socket_id,&client,&cliente_len);

		print_numbers(socket_id_client);

		close(socket_id_client);
	}

	return 0;
}

void sigint_handler(int signum){
	end_server();
}

void print_numbers(int socket_id_client){

	int numbers = 0;
	int state = 1;
	
	while(read(socket_id_client,&numbers,sizeof(int))){
		printf("O servidor recebeu = %d, state = %d\n",numbers,state);
	}

	end_server();
}

void end_server(void){
	unlink("/tmp/socket1");
	close(socket_id);
	exit(0);
}