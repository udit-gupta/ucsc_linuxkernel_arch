#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void sighup_handler() {
	int pid = getpid();
	
	signal(SIGHUP,SIG_IGN); /*reset the signal*/
	printf("\n\n  From Signal Handler with PID = %d I have received a SIGHUP signal \n",pid);
}


void sigint_handler() {
	int pid = getpid();
	
	signal(SIGINT,SIG_IGN); /*reset the signal*/
	printf("\n\n  From Signal Handler with PID = %d I have received a SIGINT signal \n",pid);
}


void sigquit_handler() {
	int pid = getpid();
	
	signal(SIGQUIT,SIG_IGN); /*reset the signal*/
	printf("\n\n  From Signal Handler with PID = %d I have received a SIGQUIT signal \n",pid);
}

int main() {

	int pid0;
	int pid=getpid();

	/*set up signal handler*/
	printf("\n Parent : Setting up SIGHUP handler with pid = %d \n\n", pid);
	signal(SIGHUP,sighup_handler);  /*set function calls*/

	printf("\n Parent : Setting up SIGINT handler with pid = %d \n\n", pid);
	signal(SIGHUP,sigint_handler);  /*set function calls*/
	
	printf("\n Parent : Setting up SIGQUIT handler with pid = %d \n\n", pid);
	signal(SIGHUP,sigquit_handler);  /*set function calls*/
	
	/*get the child process*/
	
	if( (pid0 = fork()) < 0) {
		perror("fork");
		exit(1);
	}

	if(pid0==0) {
		/* child */
	
		pid=getpid();
		printf("\n Child Process invoked with pid = %d \n\n", pid);
		/*set up signal handler*/
	
		/*set up signal handler*/
		printf("\n Parent : Setting up SIGHUP handler with pid = %d \n\n", pid);
		signal(SIGHUP,sighup_handler);  /*set function calls*/

		printf("\n Parent : Setting up SIGINT handler with pid = %d \n\n", pid);
		signal(SIGHUP,sigint_handler);  /*set function calls*/
	
		printf("\n Parent : Setting up SIGQUIT handler with pid = %d \n\n", pid);
		signal(SIGHUP,sigquit_handler);  /*set function calls*/
	
		for(;;);    // Loop forever

	} else { /*parent*/

		/*pid hold id of child*/
		pid=getpid();
		
		printf("\n Parent: sending SIGHUP Parent pid = %d \n\n", pid);
		kill(pid,SIGHUP);
		sleep(3); /*pause for 3 sec*/
		printf("\n Parent: sending SIGINT Parent pid = %d \n\n", pid);
		kill(pid,SIGINT);
		sleep(3); /*pause for 3 sec*/
		printf("\n Parent: sending SIGQUIT Parent pid = %d \n\n", pid);
		kill(pid,SIGQUIT);
		sleep(3); /*pause for 3 sec*/

	}
}

