#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int process_init_data=30;
int process_noinit_data;

char Globalbuffer[100];

void process_prints() {
	int process_local_data=1;
	char Localbuffer[100];

	printf("Pid of the process is %d\n\n",getpid());
	printf("\n1) Data Segment = %p",&process_init_data);
	printf("\n2) BSS Segment = %p",&process_noinit_data);
	printf("\n3) Code Segment = %p",&process_prints);
	printf("\n4) Stack Segment = %p",&process_local_data);
	printf("\n5) Global buffer = %p",&Globalbuffer);
	printf("\n6) Local buffer = %p",&Localbuffer);
	printf("\n\n");
}

int main() {
	process_prints();
	return 0;
}

