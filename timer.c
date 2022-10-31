/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

bool keep_going = true;
int num_alarms = 0;
time_t start, end;


void handler_alarm(int signum) { // alarm signal handler
  printf("Hello World!\n");
	num_alarms += 1;
	keep_going = false;
}

void handler_interrupt(int signum) { // interrupt signal handler
	end = time(NULL);
	printf("Caught SIGINT Signal!\n");
	printf("Time taken to execute the program: %lf seconds\n", (double)(end-start));
	printf("Number of alarms that occured: %d\n", num_alarms);
  exit(1); // exit after printing
}

int main(int argc, char * argv[])
{
	start = time(NULL);
	signal(SIGALRM, handler_alarm);
	signal(SIGINT,handler_interrupt);
	while (true) {
		alarm(1); //Schedule a SIGALRM for 1 second
		pause();
		while (keep_going);
		printf("Turing was right!\n");
		keep_going = true;
	}
	
  return 0;
}