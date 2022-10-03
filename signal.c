/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool keep_going = true;

void handler(int signum) { //signal handler
  printf("Hello World!\n");
  // exit(1); //exit after printing
	keep_going = false;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
	while (true) {
		alarm(1); //Schedule a SIGALRM for 1 second
		pause();
		while(keep_going); //busy wait for signal to be delivered
		printf("Turing was right!\n");
		keep_going = true;
	}
	
  return 0; //never reached
}