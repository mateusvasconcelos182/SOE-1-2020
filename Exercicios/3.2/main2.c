#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define meio_periodo 5000 
#define SAIDA 7

int main(void)
{
	wiringPiSetup();
	pinMode(SAIDA, OUTPUT);
		while(1)
		{
			digitalWrite(SAIDA, HIGH);
			usleep(meio_periodo);
			digitalWrite(SAIDA, LOW);
			usleep(meio_periodo);
		}
}