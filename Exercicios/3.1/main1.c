#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define SAIDA 7

int main(void)
{
	wiringPiSetup();
	pinMode(SAIDA, OUTPUT);
		while(1)
		{
			digitalWrite(SAIDA, HIGH);
			usleep(5000);
			digitalWrite(SAIDA, LOW);
			usleep(5000);
		}
}