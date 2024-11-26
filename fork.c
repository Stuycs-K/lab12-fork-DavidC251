#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "fork.h"
#include <sys/wait.h>
void ChildProcess(){
	int RandomFile = open("/dev/random", O_RDONLY, 0);
	unsigned int RandomNum;
	read(RandomFile, &RandomNum, sizeof(unsigned int));
	RandomNum = (RandomNum % 5) + 1;
	printf("RANDOM: %d \n", RandomNum);
	sleep(RandomNum);
	pid_t ReturnVal1;
	ReturnVal1 = fork();
	if(ReturnVal1 > 0){
		printf("PARENT \n");
		int stat;
		if(wait(&stat) == -1){
		}
		
		ReturnVal1 = fork();			
		
		
	}
	else if(ReturnVal1 == 0){
		read(RandomFile, &RandomNum, sizeof(unsigned int));
		RandomNum = (RandomNum % 5) + 1;
		printf("RANDOM: %d \n", RandomNum);
		sleep(RandomNum);
		printf("CHILD \n");
		exit(0);
	}
	else{
	
		printf("%d \n", ReturnVal1);
		printf("ERROR \n");
	}
	//printf("%d finished after %d seconds", , );
	


}

void ParentProcess(){



}
