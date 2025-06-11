#include<stdio.h>
#include<unistd.h>
int main(){
	int cpro1 , cpro2 , cpro3, cpro4;
	cpro1 = fork();
	cpro2 = fork();
	cpro3 = fork();
	cpro4 = fork();
	if(cpro1 < 0){
		printf("CHILD PROCESS NOT CREATED");
	}
	else if (cpro1 == 0){
		printf("PROCESS 1 CREATED");
		printf("PROCESS ID OF CHILD PROCESS %d", getpid());
	}
	printf("\n");
	if(cpro2 < 0){
		printf("CHILD PROCESS NOT CREATED");
	}
	else if (cpro2 == 0){
		printf("PROCESS 2 CREATED");
		printf("PROCESS ID OF CHILD PROCESS %d", getpid());
	}
	printf("\n");

	if(cpro3 < 0){
		printf("CHILD PROCESS NOT CREATED");
	}
	else if (cpro3 == 0){
		printf("PROCESS 3 CREATED");
		printf("PROCESS ID OF CHILD PROCESS %d", getpid());
	}
	printf("\n");
	if(cpro4 < 0){
		printf("CHILD PROCESS NOT CREATED");
	}
	else if (cpro4 == 0){
		printf("PROCESS 4 CREATED");
		printf("PROCESS ID OF CHILD PROCESS %d", getpid());
	}
	printf("\n");
	// sleep(9);
}

