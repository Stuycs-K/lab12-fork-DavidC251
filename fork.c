#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "fork.h"
#include <sys/wait.h>
void Processes(){
	printf("%d about to create 2 child processes \n", getpid());
	int RandomFile = open("/dev/random", O_RDONLY, 0);
	unsigned int RandomNum;
	read(RandomFile, &RandomNum, sizeof(unsigned int));
	RandomNum = (RandomNum % 5) + 1;

	pid_t ReturnVal1;
	ReturnVal1 = fork();
	if(ReturnVal1 > 0){
		
		ReturnVal1 = fork();
			
		
		
	}
	if(ReturnVal1 == 0){
		
		read(RandomFile, &RandomNum, sizeof(unsigned int));
		RandomNum = (RandomNum % 5) + 1;
		printf("%d %dsec \n", getpid(), RandomNum); 
		sleep(RandomNum);
		printf("%d finished after %d seconds \n", getpid(), RandomNum);
		exit(RandomNum);
	
		
		
	}
	else if(ReturnVal1 < 0){
	
		printf("%d \n", ReturnVal1);
		printf("ERROR \n");
	}
	
	int stat;
	int waitReturn = wait(&stat);
	if(waitReturn == -1){

	}
	else{
		if(WIFEXITED(stat)){
			printf("Main Process %d is done. Child %d slept for %dsec \n", getpid(), waitReturn, WEXITSTATUS(stat));
		}
		
	}
	
	
	


}


